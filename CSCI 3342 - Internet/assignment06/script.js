$(function() {
  $("img").on("click", function() {
    modal.style.display = "block";
    $("#modal_img").attr('src', $(this).attr('src'));

    	});

  window.onclick = function(event) {
    if (event.target == modal) {
        modal.style.display = "none";
    }
}

});
