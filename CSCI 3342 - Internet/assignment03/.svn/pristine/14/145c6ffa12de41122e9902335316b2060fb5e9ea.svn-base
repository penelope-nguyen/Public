$(function() {

	// Function for creating new comments.
	// Checks for validity before posting and clearing form box
	$("#post-btn").click( function() {

		var name = $("#commenter").val();
		var comment = $("#new_comment").val();

		if (isValid(name, comment)) {
			var comment_box = newComment(name, comment);

			$("#comments").prepend(comment_box);

			clearInput();
		}

		return false;
	});

	/*
	Comment deletion.
	Trying use $("button").click() does not work for dynamically
	created content, so this function was used instead.
	*/
	$(document).on("click", '.delete', function() {
		$(this).parents(".panel").remove();
	});

	/*
	Checks for validity of user's name and comment.
	It's a bit convoluted since I wanted each error message
	to tell you what you did wrong.
	*/

	function isValid(name, text) {
		// Hide old errror messages and reset name's text.
		$(".alert.name").hide();
		$(".alert.comment").hide();
		$(".alert.name").text("");

		var n_valid = true, t_valid = true;

		// Remove left and right whitespace.
		name = $.trim(name);

		/*
		Checks user input name for 3 requirements:
		- no blanks, no spaces, only alphanumerics
		Informs you of particular error. Since there was a
		possibility of non-alphanum + spaces,
		a nested condition had to be added.
		*/
		if (name == "") {
			$(".alert.name").text("Names cannot be empty.");
			n_valid = false;
		}

		else {

			if (!(name.match(/^[0-9a-zA-Z\s]+$/))) {
				$(".alert.name").text("Names can only contain letters and numbers.");
				 n_valid = false;
			}

			if (name.match(/\s/)) {
					n_valid = false;

					if ($(".alert.name").text() == "")
							$(".alert.name").text("Names cannot contain spaces.");

					else
						$(".alert.name").append("<br>" + "Names cannot contain spaces.");
				}
		}

		// Displays 0-2 error messages.
		if (!n_valid)
			$(".alert.name").show();

		// Comment requirements: no spaces.
		if (text=="") {
			$(".alert.comment").show();
			t_valid = false;
		}

		return(n_valid && t_valid);

	};

	/*
	Comment creation from cloning.
	*/

	function newComment(user, text) {
		var today = getDate();

		/*
		Original can't be hidden for use.
		"id" needs to wiped or new comments will be cloned
		with missing components once comments are deleted. 
		*/
		$("#original").show();
		var comment = $("#original").clone();
		$("#original").hide();

		comment.attr("id", "");

		comment.find("p").text(text);
		comment.find("h3").text(user).append(today); // Date is span so needs to be appended rather than +

		return comment;
	};

	// Gives date in "DD/MM//YY" format.
	function getDate() {
		var d = new Date();
		var date = (d.getMonth() + 1).toString() + "/" + d.getDate().toString() + "/" + d.getFullYear().toString();
		return "<span class='date'> " + date + "</span>";
	};

	function clearInput() {
		$("#commenter").val("");
		$("#new_comment").val("");
	}

});
