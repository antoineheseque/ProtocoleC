<!DOCTYPE html>
<html>
<head>
	<title>Protocole C</title>
</head>
<body>
	<div class="title">Default WebPage for Protocole C.</div>
	<div class="content">
		<form action="./process.php" method="post">
			<fieldset>
				<legend>Paramètres de la Scène</legend>
				Position de la caméra: <input type="number" name="camPosX" min="-100" max="100"> <input type="number" name="camPosY" min="-100" max="100"> <input type="number" name="camPosZ" min="-100" max="100">
				<br>
				Orientation de la caméra: <input type="number" name="camOX" min="-100" max="100"> <input type="number" name="camOY" min="-100" max="100"> <input type="number" name="camOZ" min="-100" max="100">
				<br>
				Taille de l'image: <input type="number" name="width" min="10" max="5000"> <input type="number" name="height" min="10" max="5000">
				<br>
				<input type="submit" name="submit" value="Ajouter des Objets">
			</fieldset>
		</form>
	</div>
</body>
</html>