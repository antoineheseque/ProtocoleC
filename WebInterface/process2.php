<?php
session_start();
/* Créer le fichier contenant les données stockées en session et lancer le script puis rediriger vers result */

if(isset($_POST['submit'])){
	$_SESSION['objX'] = $_POST['objX'];
	$_SESSION['objY'] = $_POST['objY'];
	$_SESSION['objZ'] = $_POST['objZ'];

	$_SESSION['objSX'] = $_POST['objSX'];
	$_SESSION['objSY'] = $_POST['objSY'];
	$_SESSION['objSZ'] = $_POST['objSZ'];
	$_SESSION['objType'] = $_POST['objType'];
}

if(file_exists("main.scene"))
	unlink("main.scene");

$current = file_get_contents("main.scene");
$current .= $_SESSION['camPosX'] . ";" . $_SESSION['camPosY'] . ";" . $_SESSION['camPosZ'] . "\n";
$current .= $_SESSION['camPosX'] . ";" . $_SESSION['camPosY'] . ";" . $_SESSION['camPosZ'] . "\n";
$current .= $_SESSION['width'] . "\n";
$current .= $_SESSION['height'] . "\n";
$current .= $_SESSION['objType'] . ";" . $_SESSION['objX'] . ";" . $_SESSION['objY'] . ";" . $_SESSION['objZ'] . ";" . $_SESSION['objSX'] . ";" . $_SESSION['objSY'] . ";" . $_SESSION['objSZ'] . "\n";

file_put_contents("main.scene", $current);

exec("ProtocoleC.exe");

header("Location: result.php");