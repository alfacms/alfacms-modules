my $feedback_is_switchedoff = feedbackmodule::get_power_status_for_module();
if ($feedback_is_switchedoff == 0) {
 if ($env_params[0] eq 'fbgetcode')
 {   
  my $random = 0;
  my $font = Imager::Font->new(file  => 'css/fonts/codefont.ttf', color => '000000', size  => 16);
  my $unhexedcode = feedbackmodule::hexstring_to_string($env_params[1]);
  if ($unhexedcode !~ /^[\d]+$/) {$random = rand();}
   else {$random = "0.$unhexedcode";}
  $random = sprintf("%.6f", $random);
  my @tmp = split(/\./,$random);
  my $img = Imager->new(xsize=>100, ysize=>30);
  $img->box(filled=>1, color=>'ffffff');
  $img->string(font  => $font, text => $tmp[1], x => -2, y => 27, size => 35, color => 'A0A0A0', aa => 0);
  $img = $img->rotate(degrees=>15, back => 'ffffff');
  print $co->header(-type=> 'image/png');
  binmode STDOUT;
  $img->write(fd=>fileno(STDOUT), type=>'png') or die $img->errstr;
  exit;
 }; 

 if ($env_params[0] eq 'feedback')
 {
  print $co->header(-type=>'text/html; charset=UTF-8', -Last_Modified => $global_last_modified, '-Expires' => $global_last_modified, '-Cache-Control' => 'max-age=0, must-revalidate');
  feedbackmodule::show_feedback_clientpage('');
  exit;
 };

 if ($env_params[0] eq 'feedbackform')
 {
  print $co->header(-type=>'text/html; charset=UTF-8', -Last_Modified => $global_last_modified, '-Expires' => $global_last_modified, '-Cache-Control' => 'max-age=0, must-revalidate');
  my $form = 0; if ($env_params[1] =~ /^[\d]+$/) {$form = $env_params[1];}
  print feedbackmodule::_inner_feedback_form('','','','',$form,0);
  exit;
 };
 
 if ($env_params[0] eq 'feedbackcodeform')
 {
  print $co->header(-type=>'text/html; charset=UTF-8', -Last_Modified => $global_last_modified, '-Expires' => $global_last_modified, '-Cache-Control' => 'max-age=0, must-revalidate');
  my $form = 0; if ($env_params[1] =~ /^[\d]+$/) {$form = $env_params[1];}
  my $fio = $co->param('fio');
  my $email = $co->param('email');
  my $subj = $co->param('subject');
  my $mess = $co->param('message');
  print feedbackmodule::_inner_feedback_form($fio,$email,$subj,$mess,$form,0);
  exit;
 };

 if ($env_params[0] eq 'sendmess') {
  my $fio = $co->param('fio');
  my $email = $co->param('email');
  my $subj = $co->param('subject');
  my $mess = $co->param('message');
  my $spam = feedbackmodule::hexstring_to_string($co->param('code1'));
  my $spam_conf = $co->param('code2');
  #my $formtype = '';
  my $form = 0; if ($env_params[1] > 0) {$form = $env_params[1];}
  my $redirect_value = "index.html";
  
  #my $send_to_email = 'webmaster@apopheoz.ru';
  #if ($form == 0) {$redirect_value = "index.html"; $send_to_email = 'webmaster@apopheoz.ru';}
  #if ($form == 1) {$redirect_value = "machinetime.html"; $send_to_email = 'info@apopheoz.ru';}
  #if ($form == 2) {$redirect_value = "ascue.html"; $send_to_email = 'kostas@apopheoz.ru';}
  
  my $send_to_email = 'mce-group-zakaz@mail.ru';
  if ($form == 0) {$redirect_value = "index.html"; $send_to_email = 'mce-group-zakaz@mail.ru';}
  if ($form == 1) {$redirect_value = "machinetime.html"; $send_to_email = 't1me_mach1ne@rambler.ru';}
  if ($form == 2) {$redirect_value = "ascue.html"; $send_to_email = '2042157@gmail.com';}
    
  $spam = sprintf("%.6f", "0.$spam");
  my @tmp = split (/\./,$spam);
  $spam = $tmp[1];

  if ($fio ne '' && $email ne '' && $subj ne '' && $mess ne '') {
   $fio =~ s/\@/\\\@/g;
   $subj =~ s/\@/\\\@/g;
   $mess = $co->param('message');
   if (($spam == $spam_conf) && ($spam ne '') && ($spam_conf ne '')) {
    feedbackmodule::_inner_feedback_simple_send_message_uni($send_to_email,$mess,$subj,$fio,$email);
    feedbackmodule::_inner_feedback_add_to($mess,$email,$fio,$subj,$formtype);
    #print $co->header(-type=>'text/html; charset=UTF-8', -Last_Modified => $global_last_modified, '-Expires' => $global_last_modified, '-Cache-Control' => 'max-age=0, must-revalidate'); 
    #feedbackmodule::show_feedback_clientpage($fio,$email,$subj,$mess,$form,1);
    
    print $co->redirect(-uri => "/$redirect_value");

    }
    else {print $co->header(-type=>'text/html; charset=UTF-8', -Last_Modified => $global_last_modified, '-Expires' => $global_last_modified, '-Cache-Control' => 'max-age=0, must-revalidate'); feedbackmodule::show_feedback_clientpage($fio,$email,$subj,$mess,$form,2);}
   }
   else {print $co->header(-type=>'text/html; charset=UTF-8', -Last_Modified => $global_last_modified, '-Expires' => $global_last_modified, '-Cache-Control' => 'max-age=0, must-revalidate'); feedbackmodule::show_feedback_clientpage($fio,$email,$subj,$mess,$form,3);}
  exit;
 }
}