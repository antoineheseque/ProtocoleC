<?php
session_start();

if($_SESSION['frames'] < 2){
	createFile();
	exec("ProtocoleC.exe");
	header("Location: result.php");
}
else{
	$_SESSION['camPosX'] -= round($_SESSION['frames']) / 2;
	for($i = 0; $i < $_SESSION['frames']; $i++){
		createFile();
		set_time_limit (10);
		exec("ProtocoleC.exe img/result" . $i);
		$_SESSION['camPosX'] += 1;
		$_SESSION['camPosZ'] = ($_SESSION['camPosX']*$_SESSION['camPosX'])/15;
	}
	if(file_exists("result.mp4"))
		unlink("result.mp4");
	exec("ffmpeg.exe -f image2 -i img/result%d.bmp  -b 1500k -vcodec libx264 -g 30 -filter:v \"setpts=4.0*PTS\" result.mp4");
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
	$current .= $_SESSION['width'] . "\n";
	$current .= $_SESSION['height'] . "\n";
	$current .= countArr($_SESSION['lightList']) . "\n";
	for($i = 0; $i < $_SESSION['lightCount']; $i++){
		if(!empty($_SESSION['lightList'][$i]))
			$current .= $_SESSION['lightList'][$i];
	}
	$current .= countArr($_SESSION['objList']) . "\n";
	//$current .= $_SESSION['objX'] . ";" . $_SESSION['objY'] . ";" . $_SESSION['objZ'] . ";" . $_SESSION['objSX'] . ";" . $_SESSION['objSY'] . ";" . $_SESSION['objSZ'] . ";" . $_SESSION['colorR'] . ";" . $_SESSION['colorG'] . ";" . $_SESSION['colorB'] . ";" . $_SESSION['objType'] . "\n";

	for($i = 0; $i < $_SESSION['objCount']; $i++){
		if(!empty($_SESSION['objList'][$i]))
			$current .= $_SESSION['objList'][$i];
	}

	fwrite($file, $current);
	fclose($file);
}

function countArr($arr){
	$c = 0;
	foreach($arr as $a){
		if(!empty($a))
			$c++;
	}
	return $c;
}
