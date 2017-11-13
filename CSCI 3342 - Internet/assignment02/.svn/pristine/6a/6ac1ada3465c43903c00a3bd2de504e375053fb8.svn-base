$(document).ready(function() {

  $("#menu").hide();

  // Clicking anywhere on the document will hide menu
  $(document).click(function() {
    $("#menu").hide();
  });

  // Clicking the rabbit picture will stop the previous event and show menu
  $("#menu-btn").click(function() {
    $("#menu").show();
    event.stopPropagation();
  });

  $(".thumbnail").mouseover(function() {
      $(this).css({"border-style": "solid", "border-color": "pink", "border-width": "3px"});

       $(this).mouseout(function() {
        $(this).css("border-style", "none");
      });

      // This is also excluded from the first document rule, so clicking in the
      // thumbnail will stll keep the menu open. 
      $(this).click(function(event) {
        event.stopPropagation();
    });
  });


  $(".thumbnail").click(function() {
      $("body").attr('background', $(this).attr('src'));
      $("#menu").hide();
    });

});
