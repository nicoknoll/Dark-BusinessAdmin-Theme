	<div id="wrapper">
	
		
		<?php if(!$user->isGuest()): ?>
		<?php include $config->paths->adminTemplates . 'menu.inc'; ?>
		<?php endif; ?>
		
		<section id="main">
			<header>
				<nav>
				
					<?php if(!$user->isGuest()): ?>
				
					<a href="#" id="menu" class="item menu">&equiv; <span>Menu</span></a>
					
			
					
					<a class="item" href="<?php echo $config->urls->root; ?>" style="float:right" target="_blank"><span style="color:#ccc">Visit</span> <?php echo $config->httpHost; ?></a>
										
		
						
						<div class="item" style="float:right;margin-right:40px;position:relative;height: 30px;">
							<span style="color:#ccc">Logged in as</span> <?php 
							echo $user->name;
							if($user->hasPermission('profile-edit')): ?>
							
								<div class="pop-menu north">
									<ul>
										<li><a class='action' href='<?php echo $config->urls->admin; ?>profile/'><?php echo __('profile', __FILE__); ?></a></li>
										<li><a class='action' href='<?php echo $config->urls->admin; ?>login/logout/'><?php echo __('logout', __FILE__); ?></a></li>
									</ul>
								</div>
								
							<?php endif; ?>
						
						</div>
					
					<?php endif; ?>
					
				</nav>
			
				
				<hgroup>
					
					<ul id='breadcrumb' class='nav'><?php
						foreach($this->fuel('breadcrumbs') as $breadcrumb) {
							$title = __($breadcrumb->title, __FILE__); 
							echo "\n\t\t\t\t<li><a href='{$breadcrumb->url}'>{$title}</a> &gt;</li>";
						}
						
						?>
				
					</ul>
					
					<h2><?php echo __(strip_tags($this->fuel->processHeadline ? $this->fuel->processHeadline : $page->get("title|name")), __FILE__); ?></h2>
					<?php if(trim($page->summary)) echo "<h3>{$page->summary}</h3>"; ?>
				</hgroup>
			</header>
			
			
			<div id="content">
			
			
			
				<?php include $config->paths->adminTemplates . 'notices.inc'; ?>
				
				
				
				<?php if($page->body) echo $page->body; ?>
				
				<?php echo $content?>
				
				
				
			
			</div>
			
		</section>
	
	</div>