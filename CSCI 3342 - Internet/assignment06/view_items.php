<html>

	<head>
		<title>Incredibly Simple Shopping</title>

		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css">
		<link rel="stylesheet" href="main.css">
		<script src="http://code.jquery.com/jquery.min.js"></script>
		<script type="text/javascript" src="//maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>

	</head>

	<body>

	<div class="container">

		<div class="page-header">
			<h1>Buy More!</h1>
		</div>

		<div class="row col-md-8 col-md-offset-2">

		<!-- on button click, POST back to self (controller) -->
		<form method="POST" action="">

			<table class="table">

			<thead>
				<tr>
					<th></th>
					<th><a href="Shopping.php?cat=name">Name</a>
					</th>
					<th class="price"><a href="Shopping.php?cat=price">Price</a></th>
				</tr>
			</thead>

			<!--
				use PHP to generate these table rows based on what is in the $items array.
				pay attention to the name/value attributes!

			-->

			<!-- Example code from Dr. Tomai -->

			<?php
				if ($sorted) {
					$items_list = $sorted_items;
				}
				else {
					require_once("data.php");
					$items_list = $items;
				}

				foreach ($items_list as $item) { ?>
					<tr>
						<td rowspan="2">
							<input type="checkbox" name="item_id[]" value=<?=$item["id"]?>>
							<img class="thumb" src=<?=$item["img"]?>>
						</td>
						<td><span class="name"><?=$item["name"]?></span></td>
						<td class="price">$<?= number_format($item["price"], 2 , ".", ",")?></td>
					</tr>
					<tr><td colspan="2"><?=$item["desc"]?></td></tr>

				<?php
				 }

			?>
			<!-- end generating table rows -->

			</table>

		<!--
			notice the button has a name attribute, so that you can tell they POSTed even if they didn't
			select any checkboxes!
		-->
			<button class="btn btn-primary" name="buy">Buy!</button>
		</form>

		<?php
			if (!$selection) { ?>
				<div class="alert alert-danger">
  				<strong>Warning!</strong> You have not made a selection.
				</div>
		<?php	} ?>

		<div id = "modal" class="modal">
				<img class="modal-content" id="modal_img">
		</div>

		</div>

		<script src="script.js"></script>


	</body>

</html>
