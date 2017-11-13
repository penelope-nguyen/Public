
$(function() {
	
	
	$.getJSON("email_list.js", function(items){
		console.log("works!");
		
		
		$.each(items, function(i, val) { 
			addEmail(val);
			}) 
		})
	.fail(function() {
		console.log("broke!");
	})
	
	function addEmail(email) { 
		var body = $(".email-body.original").clone();

		var header = $(".email-header.original").clone();

		body.removeClass("original");
		header.find(".sender").text(email.sender);
		header.find(".subject").text(email.subject);
		header.find(".date").text(email.date);
		header.attr("id", email.id);

		header.removeClass("original");
		body.find(".recipient").text("");
		body.find(".body").text("");


		$("#email_list").prepend(body);
		$("#email_list").prepend(header)
	}

	function loadEmail(id, body) { 

		var fname = id + ".js";
		$.getJSON(fname, function(email){

			body.find(".recipient").text(email.recipient);
			body.find(".body").text(email.body);
		/* 
		$.each(items, function(i, val) { 
			})*/ 
		})
	.fail(function() {
		console.log("broke!");
	})
	}

	// show/hide emails when click on headers
	$(document).on("click", "tr.email-header", function(){

		var next_tab = $(this).next("tr.email-body");
		
		if (next_tab.hasClass("email-body"))  { 			
			var body_text = next_tab.find(".body").text();
			if (body_text == "") { 
				var id = $(this).attr("id");
				loadEmail(id, next_tab);
			}
		}
		next_tab.eq(0).toggle();
	});

	// hide email on click
	$(document).on("click", "tr.email-body", function(){
		$(this).hide();
	});
	
})
