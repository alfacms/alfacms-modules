my $weblog_is_switchedoff= weblogmodule::get_power_status_for_module();
if ($weblog_is_switchedoff == 0) {
 my $WebLogPage = weblogmodule::check_action_for_static_page($env_params[0]);
 if ($WebLogPage > 0) {
  print $co->header(-type=>'text/html; charset=UTF-8', -Last_Modified => $global_last_modified, '-Expires' => $global_last_modified, '-Cache-Control' => 'max-age=0, must-revalidate');	
  weblogmodule::show_weblog_clientpage($env_params[0]);
  exit;
 }
}