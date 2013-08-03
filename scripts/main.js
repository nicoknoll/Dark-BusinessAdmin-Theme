$(document).ready(function() {
	
	function toggleMainnav() {
		if($('#mainnav').hasClass('open')) {
			$('#mainnav').removeClass('open');
			$('#pages').removeClass('open');
			setWrapperPadding(0);
			
			$.cookie("pw_menu_pages", null, { path: '/'  });
			$.cookie("pw_menu_mainnav", null, { path: '/'  });
			
		} else {
			$('#mainnav').addClass('open');
			setWrapperPadding(250);
		
			$.cookie("pw_menu_mainnav", "open", { expires: 7, path: '/'  });
		}
	}
	
	function togglePages() {
		if($('#pages').hasClass('open')) {
			$('#pages').removeClass('open');
			$('.MenuPages').removeClass('on');
			setWrapperPadding(250);
			
			$.cookie("pw_menu_pages", null, { path: '/'  });
			
		} else {
			$('#pages').addClass('open');
			$('#mainnav').addClass('open');
			$('.MenuPages').addClass('on');
			setWrapperPadding(650);
			
			$.cookie("pw_menu_pages", "open", { expires: 7, path: '/' });
			$.cookie("pw_menu_mainnav", "open", { expires: 7, path: '/'  });
		}
	}
	
	function setWrapperPadding(padding) {
		$('#wrapper').css('padding-left', padding);
	}


	$('#menu, #closeMainnav').click(function(){
		toggleMainnav();
		return false;
	});	
	
	$('a[href="' + pwconfig.urls.admin + 'page/"], a[href="' + pwconfig.urls.admin + '"], a[href="' + pwconfig.urls.admin + 'page/list/"], #closePages').click(function(){
		togglePages();
		return false;
	});

	if($.cookie("pw_menu_pages") == "open") {
		togglePages();
	} else if($.cookie("pw_menu_mainnav") == "open") {
		toggleMainnav();
	}
	
	
	if($(location).attr('pathname') == pwconfig.urls.admin + 'page/' && $.cookie("pw_menu_pages") != "open") {
		togglePages();
	}

	
});

