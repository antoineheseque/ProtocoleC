<?php
session_start();
if(isset($_POST['index'])){
	$_SESSION['objCount'] = count($_SESSION['objList'])-1;
	array_splice($_SESSION['objList'], $_POST['index']);
	//unset($_SESSION['objList'][$_POST['index']]);
}

header("Location: process.php");