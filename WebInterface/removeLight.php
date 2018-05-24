<?php
session_start();
if(isset($_POST['index'])){
	$_SESSION['lightCount'] = count($_SESSION['lightList'])-1;
	array_splice($_SESSION['lightList'], $_POST['index']);
	//unset($_SESSION['objList'][$_POST['index']]);
}

header("Location: process.php");
