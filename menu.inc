<aside id="mainnav">
	<a href="#" id="closeMainnav" class="navitem close">&#10005;</a>

	
	<?php
		foreach($pages->get($wire->config->adminRootPageID)->children("check_access=0") as $p) {
		
			if(!$p->viewable()) continue; 
		
			$showItem = $user->isSuperuser() ? true : false;
			$info = array();
		
			if(!$showItem) { 
				$checkPages = $p->numChildren ? $p->children("check_access=0") : array($p); 
				foreach($checkPages as $child) {
					if($child->viewable()) {
						$showItem = true;
						break;
					}
				}
			}
		
			if($showItem) {
				$class = strpos($page->path, $p->path) === 0 ? ' class="on navitem Menu'.ucfirst(strtolower(strip_tags((string)$p->get('title|name')))).'"' : 'class="navitem Menu'.ucfirst(strtolower(strip_tags((string)$p->get('title|name')))).'"';
				$title = strip_tags((string)$p->get('title|name'));
				echo '<a href="'.$p->url.'" '.$class.'>'.$title.'</a>'; 
			}
		}		
	?>
	
	
	<div class="search">
		<input id="ProcessPageSearchQuery" type="text" placeholder="Enter search term">
	</div>
	
	<div class="copyright">
		<a href="http://processwire.com">ProcessWire</a> <?php echo $config->version . ' <!--v' . $config->systemVersion; ?>--><br />
		&copy; <?php echo date('Y'); ?> <a href="https://twitter.com/rc_d">Ryan Cramer</a><br />
		<br />
		<a href="http://processwire.com">Dark Business</a> 1.0<br />
		&copy; <?php echo date('Y'); ?> <a href="http://nico.is">Nico Knoll</a>
	</div>
	
	
	
	
	
	<?php include $config->paths->adminTemplates . 'pagelist.inc'; ?>
	
</aside>