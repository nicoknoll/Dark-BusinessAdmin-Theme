<?php

if (count($notices) > 0) {
	
	echo "<ul id='notices' class='ui-widget'>";
	
	foreach($notices as $notice) {
	
		$class = ' NoticeMessage';
		$text = $notice->text; 
		$label = 'Note';
		$icon = '';
	
		if($notice instanceof NoticeError || $notice->flags & Notice::warning) {
			
			if($notice->flags & Notice::warning) {
				$class .= ' NoticeWarning';
				$label = 'Warning';
			} else {
				$class .= ' NoticeError';
				$label = 'Error';
			}
		}
	
		$text = '<span class="NoticeLabel">'.$label.'</span>: '.$text;
	
		echo "\n\t\t<li class='$class'><div class='container'><p>{$text}</p></div></li>";
	
	}
	
	echo "\n\t</ul><!--/notices-->";

}