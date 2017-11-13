$(document).ready(function () {

  // Hide all error messages at the beginning, show for invalidation
  $(".error").hide();

  // Name validation //
  $("#name").focusout(function() {

        var input = $(this).val();

        if (!input)
          $(".error#name").show();
        else
          $(".error#name").hide();
    });

  // Date validation //
  $("#DOB").focusout(function() {

      var input = $(this).val();

      if (moment(input).isValid()) {
        var date = moment(input).format("MM/DD/YYYY");
        $(this).val(date);
        $(".error#DOB").hide();
      }

      else
        $(".error#DOB").show();
    });

// Checkbox validation  //
  $("#check").change(function() {
    // Chose .change over .click in case user prefers to select via keyboard

     if ($(this).is(':checked'))
      $("select").prop('disabled', false);

     else {
      $("select").prop('disabled', true);
      $("select").val("");
    }
  });

});
