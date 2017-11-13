<html>

	<head>
		<title>Incredibly Simple Shopping</title>

		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css">
		<link rel="stylesheet" href="main.css">

		<script src="http://code.jquery.com/jquery.min.js"></script>
	</head>

	<body>

		<div class="container">

			<div class="page-header">
				<h1>Buy More!</h1>
			</div>

			<div class="row col-md-8 col-md-offset-2">

				<!-- Added in dollar sign + formatted the price properly --->
				<h3>Total Price: $<?=number_format($price, 2 , ".", ",")?></h3>

				<p>Thank you for shopping with us!</p>

				<p><a href="Shopping.php">Back to the stuff</a></p>

			</div>
		</div>
	</body>

</html>
