<?php

if($_GET['id']) $this->input->get->open = $_GET['id'];

$pl = $this->modules->get("ProcessPageList");
$pl->set('id',1);
$pagelist = $pl->execute();
		


$searchForm = $user->hasPermission('page-edit') ? $modules->get('ProcessPageSearch')->renderSearchForm() : '';
$bodyClass = $input->get->modal ? 'modal' : '';

$bodyClass .= $user->isGuest() ? ' login' : '';

if(!isset($content)) $content = '';

$config->styles->prepend($config->urls->adminTemplates . "styles/style.css"); 
$config->styles->append($config->urls->adminTemplates . "styles/inputfields.css"); 
$config->styles->append($config->urls->adminTemplates . "styles/ui.css"); 
$config->styles->append($config->urls->adminTemplates . "styles/JqueryUI/JqueryUI.css"); 
$config->scripts->append($config->urls->adminTemplates . "scripts/inputfields.js"); 
$config->scripts->append($config->urls->adminTemplates . "scripts/jquery.cookie.js"); 
$config->scripts->append($config->urls->adminTemplates . "scripts/main.js"); 

$browserTitle = wire('processBrowserTitle'); 
if(!$browserTitle) $browserTitle = __(strip_tags($page->get('title|name')), __FILE__) . ' &bull; ProcessWire';


?>
<!DOCTYPE html>
<html lang="<?php echo __('en', __FILE__); // HTML tag lang attribute
	/* this intentionally on a separate line */ ?>"> 
<head>
	<meta http-equiv="content-type" content="text/html; charset=utf-8" />
	<meta name="robots" content="noindex, nofollow" />
	<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">

	<title><?php echo $browserTitle; ?></title>

	<script type="text/javascript">
		<?php



		$jsConfig = $config->js();
		$jsConfig['debug'] = $config->debug;
		$jsConfig['urls'] = array(
			'root' => $config->urls->root, 
			'admin' => $config->urls->admin, 
			'modules' => $config->urls->modules, 
			'core' => $config->urls->core, 
			'files' => $config->urls->files, 
			'templates' => $config->urls->templates,
			'adminTemplates' => $config->urls->adminTemplates,
			); 

		?>
		
	

		var pwconfig = <?php echo json_encode($jsConfig); ?>;
		var config = pwconfig;
	</script>

	<?php foreach($config->styles->unique() as $file) echo "\n\t<link type='text/css' href='$file' rel='stylesheet' />"; ?>
	<?php foreach($config->scripts->unique() as $file) echo "\n\t<script type='text/javascript' src='$file'></script>"; ?>

</head>

<body<?php if($bodyClass) echo " class='$bodyClass'"; ?>>
	
	
	
	<?php
	if(!$user->isGuest()) {
		include $config->paths->adminTemplates . 'main.inc';
	} else {
		include $config->paths->adminTemplates . 'login.inc';
	}
	
	?>
	
	
</body>
</html>