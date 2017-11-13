var imgs = { 0 : "http://animalcontrolphx.com/wp-content/uploads/2013/05/gophers-400.jpg",
             1 : "https://i.imgur.com/jW2sPeL.jpg", // last link 404'd so i made a new one
             2 : "https://www.waikikiaquarium.org/wp-content/uploads/2013/11/octopus_620.jpg"
           }

$(function() {

  function spawnCritters(choice) {
    var fname = "data" + choice + ".js";

    $.getJSON(fname, function(position){
  		$.each(position, function(i, pos) {
        var image = $('<img>',{src:imgs[choice], width:40, height: 40, class: "critter"})
        image.css({left: pos[0], top: pos[1], position:'absolute'});
        $("#map-container").append(image);
  			})
  		})
  	.fail(function() {
  		console.log("broken!");
  	})
  }

  // event listener for option selector
  $("#choice").change(function () {

    // remove any image that has already been added to the document
    $('.critter').remove();

    var choice = $(this).val();
    spawnCritters(choice);

  });

});
