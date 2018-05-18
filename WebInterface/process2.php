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

	$_SESSION['colorR'] = $_POST['colorR'];
	$_SESSION['colorG'] = $_POST['colorG'];
	$_SESSION['colorB'] = $_POST['colorB'];
}

if($_SESSION['frames'] < 2){
	createFile();
	exec("ProtocoleC.exe");
	header("Location: result.php");
}
else{
	$_SESSION['lightPosX'] -= round($_SESSION['frames']*2);
	for($i = 0; $i < $_SESSION['frames']; $i++){
		createFile();
		exec("ProtocoleC.exe img/result" . $i);
		$_SESSION['lightPosX'] += 4;
	}
	if(file_exists("result.mp4"))
		unlink("result.mp4");
	exec("ffmpeg.exe -f image2 -i img/result%d.bmp  -b 1500k -vcodec libx264 -g 30 -filter:v \"setpts=2.0*PTS\" result.mp4");
	for($i = 0; $i < $_SESSION['frames']; $i++){
		unlink("img/result" . $i . ".bmp");
	}
	header("Location: result.php");
}

function createFile(){
	if(file_exists("main.scene"))
		unlink("main.scene");
	$file = fopen("main.scene", "w");
	$current = "";
	$current .= $_SESSION['camPosX'] . ";" . $_SESSION['camPosY'] . ";" . $_SESSION['camPosZ'] . "\n";
	$current .= $_SESSION['camPosX'] . ";" . $_SESSION['camPosY'] . ";" . $_SESSION['camPosZ'] . "\n";
	$current .= $_SESSION['addLight'] . ";" . $_SESSION['lightPosX'] . ";" . $_SESSION['lightPosY'] . ";" . $_SESSION['lightPosZ'] . "\n";
	$current .= $_SESSION['width'] . "\n";
	$current .= $_SESSION['height'] . "\n";
	$current .= "1\n";
	$current .= $_SESSION['objX'] . ";" . $_SESSION['objY'] . ";" . $_SESSION['objZ'] . ";" . $_SESSION['objSX'] . ";" . $_SESSION['objSY'] . ";" . $_SESSION['objSZ'] . ";" . $_SESSION['colorR'] . ";" . $_SESSION['colorG'] . ";" . $_SESSION['colorB'] . ";" . $_SESSION['objType'] . "\n";

	fwrite($file, $current);
	fclose($file);
}
