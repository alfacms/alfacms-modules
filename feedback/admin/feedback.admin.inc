if ($env_params[1] eq 'admfeedback')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) 
    {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 feedbackmodule::show_feedback_startpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),0);
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
};

if ($env_params[1] eq 'delfeedback')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) 
    {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 feedbackmodule::_inner_feedback_delete($env_params[2]);
	 feedbackmodule::show_feedback_startpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),1);
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
}; 

if ($env_params[1] eq 'admfeedbackmovedown')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 if ($env_params[2] =~ /^[\d]+$/) {feedbackmodule::_inner_feedback_sgmovedown ($env_params[2]);}
	 feedbackmodule::show_feedback_startpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),0);	
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
}; 

if ($env_params[1] eq 'admfeedbackmoveup')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 if ($env_params[2] =~ /^[\d]+$/) {feedbackmodule::_inner_feedback_sgmoveup($env_params[2]);}
	 feedbackmodule::show_feedback_startpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),0);	
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
};