<!DOCTYPE html>
<html>
<head>
	<title>Protocole C</title>
	<link rel="stylesheet" type="text/css" href="main.css">
</head>
<body>
	<link rel="icon" type="image/png" href="ProtocoleC.jpg" />
	<div class="title">Protocole C: Système de Ray-Tracing.</div>
	<div class="content">
		<form action="./process.php" method="post">
			<fieldset>
				<legend>Paramètres de la Scène</legend>
				<div class="text">Position de la caméra: </div>
				<div class="pos"><input type="number" name="camPosX" min="-100" max="100"> <input type="number" name="camPosY" min="-100" max="100"> <input type="number" name="camPosZ" min="-100" max="100"></div>
				<br><br>
				<div class="text">Orientation de la caméra: </div>
				<div class="pos"><input type="number" name="camOX" min="-100" max="100"> <input type="number" name="camOY" min="-100" max="100"> <input type="number" name="camOZ" min="-100" max="100"></div>
				<br><br>
				<div class="text">Taille de l'image: </div><div class="pos">
				<input type="number" name="width" min="10" max="5000"> <input type="number" name="height" min="10" max="5000"></div>
				<br>
				<div class="submit"><input type="submit" name="submit" value="Ajouter des Objets"></div>
			</fieldset>
		</form>
	</div>
</body>
<footer>
	<h4>Un site créé par Antoine Héséque, Loïc Caron, Julien Becquet et Louis Jeannin</h4> <h6><a href="https://bowmanvszombies.fr/">BowmanVSZombies</a></h6>
</footer>
</html>