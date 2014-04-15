if ($env_params[1] eq 'admsystemgallery')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 my $got_page = $env_params[2];
	 if ($got_page !~ /^[\d]+$/) {$got_page = 0;}
	 systemgallerymodule::sysgallery_startpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$got_page,0);
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
}; 

if ($env_params[1] eq 'admgalcrobjform')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 #systemgallerymodule::sysgallery_createpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$gallerytype,1);
	 print systemgallerymodule::_inner_sysgallery_createpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$gallerytype,1);
	 exit;
	 }
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
}; 

if ($env_params[1] eq 'admgalpostobj')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 my $uplmess = '';
	 my $objID = time;
	 my $objprio = 0;
	 my $objsort = time-1391000000;
	 my $objname = $co->param('header');
	 my $objdesc = $co->param('comment');
	 $objdesc =~ s/[\r\n]+/\<br\>/g;

	 my $objhtmlcode = 0;
	 my $objlinks = 0;

	 systemgallerymodule::add_to_gallery($objsort,$objID,$objprio,$objname,$objdesc,$objhtmlcode,$objlinks);
	 systemgallerymodule::sysgallery_startpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),0,0);	
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
}; 

if ($env_params[1] eq 'admgaleditobj')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 print systemgallerymodule::_inner_sysgallery_editpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$env_params[2],$env_params[3]);	
	 exit;
	 }
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
}; 

if ($env_params[1] eq 'admgalmodobj')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) {
	
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 my $uplmess = '';
	 my $objID = $env_params[2];
	 my $objprio = 0;
	 my $objdate = $co->param('date');
	 my $objname = $co->param('header');
	 my $objdesc = $co->param('comment');
	 $objdesc =~ s/[\r\n]+/\<br\>/g;

	 my $objhtmlcode = 0;
	 my $objlinks = 0;

	 systemgallerymodule::modify_gallery($objID,$objdate,$objprio,$objname,$objdesc,$objhtmlcode,$objlinks);
	 systemgallerymodule::sysgallery_startpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$env_params[3],0);

	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
};

if ($env_params[1] eq 'admgaldelobj')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) {
	print $co->header(-type=>'text/html; charset=UTF-8');
	systemgallerymodule::delete_gallery($env_params[2]);
	systemgallerymodule::accurate_del_files_fromdir($env_params[2],'images/systemgallery/upload');
	systemgallerymodule::sysgallery_startpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),0,0);
	exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
};

if ($env_params[1] eq 'admgaleditphotos')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 systemgallerymodule::sysgallery_editphotopage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$env_params[2],0);	
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
}; 

if ($env_params[1] eq 'admgaleditphoto')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) {
	print $co->header(-type=>'text/html; charset=UTF-8');
	my $objID = $env_params[2];
	my $sortorder = $co->param('sortorder');
	my @checkedmain = ();

	my @tmpsortorder = systemgallerymodule::get_sysgallery_img_bynum('images/gallery/upload/',$objID);
	if ($sortorder ne "") {@tmpsortorder = split (/\,/,$sortorder);}
	for(my $inx = 0; $inx <= $#tmpsortorder; $inx++) {
	 if ($co->param("useimg$inx") ne '') {push(@checkedmain,$co->param("useimg$inx"));}
	 } 

	if ($co->param('photofile0') ne '') {
	  my @file_names_to_info = ();
	  my $autoresize = $co->param('autoresize');
	  for($i=0;$i<1;$i++) {
		$down_load_field = 'photofile'.$i;
		$got_filename = $co->param($down_load_field);
		my $fileindex = systemgallerymodule::getlastuploadindex($objID);
		if ($fileindex < 10) {$fileindex = "0".$fileindex;}
		my @ext_mass = split /\./,$got_filename; $filename = $objID."_$fileindex.".$ext_mass[$#ext_mass];
		
		if ($got_filename ne '' && $filename =~ /\.jpg$/i) 
	    	  {
		  $filename = lc($filename);
		  $uplmess .= systemgallerymodule::download_orig_photo($got_filename,$filename,$down_load_field,$autoresize)."<br>";
	    	  push(@file_names_to_info,$filename);	
	    	  }
		} #for
	 }
	 #else {$uplmess = "<div class=error>ERROR: form with empty fields!</div><br>\r\n";}	

	systemgallerymodule::sysgallery_editphotopage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$env_params[2],2,$uplmess);	
	exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
};

if ($env_params[1] eq 'admdelimgfromsystemgallery')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 my @images = reverse(systemgallerymodule::get_sysgallery_img_bynum('images/systemgallery/upload/',$env_params[2]));
	 for(my $k=0; $k<=$#images;$k++)
	  {
	  	my $file_name = "$env_params[2]_$env_params[3]";
	  	if ($images[$k] =~ /^$file_name\./) {unlink("images/systemgallery/upload/$images[$k]"); last;}
	  }
	 systemgallerymodule::sysgallery_editphotopage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$env_params[2],0);	
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
}; 

if ($env_params[1] eq 'admsysgalmovedown')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 if ($env_params[2] =~ /^[\d]+$/) {systemgallerymodule::sysgallery_sgmovedown($env_params[2]);}
	 systemgallerymodule::sysgallery_startpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$env_params[3],0);	
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
}; 

if ($env_params[1] eq 'admsysgalmoveup')
{  
    sessiontools::clear_currlogin();
    $check_auth = sessiontools::valid_user($env_params[0]);
    if ($check_auth==1) {
	 print $co->header(-type=>'text/html; charset=UTF-8');
	 if ($env_params[2] =~ /^[\d]+$/) {systemgallerymodule::sysgallery_sgmoveup($env_params[2]);}
	 systemgallerymodule::sysgallery_startpage($env_params[0],sessiontools::get_login_bysesid($env_params[0]),$env_params[3],0);	
	 exit;
	}
    print $co->header(-type=>'text/html; charset=UTF-8');
    admin_cms::show_login_page();
    exit;
};