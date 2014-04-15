if ($env_params[1] eq 'admweblog')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) 
    {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 my $got_page = $env_params[2];
	 if ($got_page !~ /^[\d]+$/) {$got_page = 0;}
	 weblogmodule::show_weblog_startpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$got_page,0);
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
};

if ($env_params[1] eq 'crweblograzdel')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) 
    {
	 my $got_page = $env_params[2];
	 if ($got_page !~ /^[\d]+$/) {$got_page = 0;}
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 print weblogmodule::_inner_weblog_createrazdelpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$got_page);
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
}; 


if ($env_params[1] eq 'crnewweblograzdel')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) 
    {
	 my $got_page = 0; #my $got_page = $env_params[2];
	 #if ($got_page !~ /^[\d]+$/) {$got_page = 0;}
     my $flag = 0;
     my $uplmess = '';
	 #my $weblog_sort = time-1391000000;
	 my $weblog_sort = time;
	 my $weblog_id = $weblog_sort;
	 my $seochpu = $co->param('seochpu'); 
	 my $seotitle = $co->param('seotitle');
	 my $seometadescr = $co->param('seometadescr');
	 my $seometakeys = $co->param('seometakeys');
	 my $date = $co->param('date');
	 my $header = $co->param('header'); 
	 my $comment = $co->param('comment'); 
	
	 $comment =~ s/[\r\n]+/\<br\>/g;

	 if ($seochpu ne '' && $comment ne '' && $header ne '') {$flag = 1; weblogmodule::_inner_weblog_add($weblog_sort,$weblog_id,$date,$seochpu,$seotitle,$seometadescr,$seometakeys,$header,$comment);}
	  else {$flag = 2; $uplmess = "***error: found empty elements in form!";}

	 print $co->header(-type=>'text/html; charset=UTF-8');
	 weblogmodule::show_weblog_startpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$got_page,$flag,$uplmess);
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
}; 


if ($env_params[1] eq 'delweblog')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) 
    {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 my $got_page = $env_params[3];
	 if ($got_page !~ /^[\d]+$/) {$got_page = 0;}
	 weblogmodule::_inner_weblog_delete($env_params[2]);
	 weblogmodule::show_weblog_startpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$got_page,1);
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
}; 


if ($env_params[1] eq 'editweblog')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) 
    {
	 my $got_page = $env_params[3];
	 if ($got_page !~ /^[\d]+$/) {$got_page = 0;}
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 print weblogmodule::_inner_weblog_editpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$env_params[2],$got_page,0);
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
}; 

if ($env_params[1] eq 'modweblograzdel')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) 
    {
     my $got_page = $env_params[3];
	 if ($got_page !~ /^[\d]+$/) {$got_page = 0;}
     my $flag = 1;
     my $uplmess = '';
	 my $weblog_sort = $env_params[2];
	 my $weblog_id = $env_params[2];
	 my $seochpu = $co->param('seochpu'); 
	 my $seotitle = $co->param('seotitle');
	 my $seometadescr = $co->param('seometadescr');
	 my $seometakeys = $co->param('seometakeys');
	 my $date = $co->param('date');
	 my $header = $co->param('header'); 
	 my $comment = $co->param('comment'); 
	
	 $comment =~ s/[\r\n]+/\<br\>/g;

	 if ($seochpu ne '' && $comment ne '' && $header ne '') {weblogmodule::_inner_weblog_modify($weblog_sort,$weblog_id,$date,$seochpu,$seotitle,$seometadescr,$seometakeys,$header,$comment);}
	  else {$flag = 2; $uplmess = "***error: found empty elements in form!";}

	 print $co->header(-type=>'text/html; charset=UTF-8');
	
	 weblogmodule::show_weblog_startpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$got_page,$flag,$uplmess);
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
};

if ($env_params[1] eq 'addtexttoweblograzdel')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 my $got_page = $env_params[3];
	 if ($got_page !~ /^[\d]+$/) {$got_page = 0;}
	 weblogmodule::show_weblog_podrazdeltextpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$env_params[2],$got_page,0);
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
}; 

if ($env_params[1] eq 'admweblogpodrazdelpost')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) 
    {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 my $got_page = $env_params[3];
	 if ($got_page !~ /^[\d]+$/) {$got_page = 0;}
	 weblogmodule::_inner_weblog_savepodrazdelcontent($co->param('pagecontent'),$env_params[2]);
	 weblogmodule::show_weblog_podrazdeltextpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$env_params[2],$got_page,1);
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
}; 

if ($env_params[1] eq 'admweblogmovedown')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 my $got_page = $env_params[3];
	 if ($got_page !~ /^[\d]+$/) {$got_page = 0;}
	 if ($env_params[2] =~ /^[\d]+$/) {weblogmodule::_inner_weblog_sgmovedown ($env_params[2]);}
	 weblogmodule::show_weblog_startpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$got_page,0);	
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
}; 

if ($env_params[1] eq 'admweblogmoveup')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 my $got_page = $env_params[3];
	 if ($got_page !~ /^[\d]+$/) {$got_page = 0;}
	 if ($env_params[2] =~ /^[\d]+$/) {weblogmodule::_inner_weblog_sgmoveup($env_params[2]);}
	 weblogmodule::show_weblog_startpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$got_page,0);	
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
};