<?php
  // include the data file to fake database data
  require_once("data.php");

  // do stuff!

  $selection = true;
  $sorted = false;
  $sorted_items = [];
  if ($_POST) {
    if(!empty($_POST['item_id'])) {
      $price = 0;
      foreach ($_POST["item_id"] as $checked) {
        foreach ($items as $item) {
          if ($item["id"] == $checked)
            $price += $item["price"];

        }
      }
      require_once("view_confirm.php");
      die();
    }
    else {
      $selection = false;
    }
  }

  if(isset($_GET['cat'])) {
    $sort_key = $_GET['cat'];
    sortItems($sort_key, $sorted_items);
    $sorted = true;
  }


  // selection sort 
  function sortItems($key, &$list) {
    include("data.php");
    $length = count($items);
    for ($i = 0; $i < $length; $i++) {
      $min = $items[$i][$key];
      for ($j = $i; $j < $length; $j++) {
        $current_val = $items[$j][$key];
        if ($current_val < $min) {
          $temp = $items[$i];
          $items[$i] = $items[$j];
          $items[$j] = $temp;
        }
      }
    }

    $list = $items;
  }

  // include the view items page
  require_once("view_items.php");
  die();
?>
