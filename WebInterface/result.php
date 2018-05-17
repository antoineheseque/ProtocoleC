<!DOCTYPE html>
<html>
<head>
	<title>Protocole C</title>
	<link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
	<?php
		session_start();
		if($_SESSION['frames'] < 2){
			if(file_exists("result.bmp"))
				echo "<img src=\"result.bmp\">";
			else
				echo "Erreur dans le programme";
		}
		else{
			if(file_exists("result.mp4"))
				echo "<video width=\"1000\" autoplay loop><source src=\"result.mp4\" type=\"video/mp4\">Your browser does not support HTML5 video.</video>";
			else
				echo "Erreur dans le programme";
		}

	?>
	<br>
	<div class="title"><a href="index.php">Retour à l'accueil</a></div>
</body>
</html>
