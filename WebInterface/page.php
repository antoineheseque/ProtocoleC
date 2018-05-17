<!DOCTYPE html>
<html>
<head>
	<title>Protocole C</title>
	<link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
	<link rel="icon" type="image/png" href="ProtocoleC.jpg" />
	<div class="title">Protocole C : Système de Ray-Tracing</div>
	<div class="content">
		<form action="./process.php" method="post">
			<fieldset>
				<legend>Paramètres de la Scène</legend>
				<div class="text">Position de la caméra : </div>
				<div class="pos"><input type="number" name="camPosX" value="0" min="-100" max="100" required> <input type="number" name="camPosY" value="2" min="-100" max="100" required> <input type="number" name="camPosZ" value="0" min="-100" max="100" required></div>
				<br><br>
				<div class="text">Orientation de la caméra : </div>
				<div class="pos"><input type="number" name="camOX" value="0" min="-100" max="100" required> <input type="number" name="camOY" value="0" min="-100" max="100" required> <input type="number" name="camOZ" value="1" min="-100" max="100" required></div>
				<br><br>
				<div class="text">Taille de l'image : </div><div class="pos">
				<input type="number" name="width" value="1280" min="10" max="5000" required> <input type="number" name="height" value="720" min="10" max="5000" required></div>
				<br><br>
				<div class="text">Nombre de Frames:</div><div class="pos"><input type="number" name="frames" value="1" min="1" max="50" required></div>
				<div class="submit"><input type="submit" name="submit" value="Ajouter des Objets"></div>
			</fieldset>
		</form>
	</div>
</body>
<footer>
	<h4>Un site créé par Antoine Héséque, Loïc Caron, Julien Becquet et Louis Jeannin</h4> <h6><a href="https://bowmanvszombies.fr/">BowmanVSZombies</a></h6>
</footer>
</html>