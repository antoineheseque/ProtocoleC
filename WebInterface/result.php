<!DOCTYPE html>
<html>
<head>
	<title>Protocole C</title>
	<link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
	<?php
		if(file_exists("result.png"))
			echo "<img src=\"result.png\">";
		else
			echo "Erreur dans le programme";
	?>
	<br>
	<div class="title"><a href="index.php">Retour à l'accueil</a></div>
</body>
</html>
