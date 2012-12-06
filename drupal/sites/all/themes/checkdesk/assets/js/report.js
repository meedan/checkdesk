(function ($) {

	Drupal.behaviors.reports = {
		attach: function () {
			// show report activity
			$('.report-activity > header').click(function(event) {
				var target = $(this);
				var element = target.parent().attr('id');
				$('#'+ element + ' .activity-wrapper').slideToggle('fast');
				$('#'+ element).toggleClass('open');
				return false;
			});

			$('a.twitter').click(function(event) {
				event.preventDefault();
				// set URL
				var loc = $(this).attr('href');
				// set title 
				var title  = $(this).attr('title');
				// open a window
				openShareWindow('twitter', loc, title);
			});

			$('a.facebook').click(function(event) {
				event.preventDefault();
				// set URL
				var loc = $(this).attr('href');
				// set title 
				var title  = $(this).attr('title');
				// open a window
				openShareWindow('facebook', loc, title);
			});

			$('a.google').click(function(event) {
				event.preventDefault();
				// set URL
				var loc = $(this).attr('href');
				// set title 
				var title  = $(this).attr('title');
				// open a window
				openShareWindow('google', loc, title);
			});
			
			function openShareWindow(service, loc, title) {
				if(service == 'twitter') {
					window.open('http://twitter.com/share?url=' + loc + '&text=' + title, 'twitterwindow', 'height=450, width=550, top='+($(window).height()/2 - 225) +', left='+$(window).width()/2 +', toolbar=0, location=0, menubar=0, directories=0, scrollbars=0');	
				}
				if(service == 'facebook') {
					window.open('https://www.facebook.com/sharer.php?u=' + loc + '&t=' + title, 'facebookwindow', 'height=450, width=550, top='+($(window).height()/2 - 225) +', left='+$(window).width()/2 +', toolbar=0, location=0, menubar=0, directories=0, scrollbars=0');		
				}
				if(service == 'google') {
					window.open('https://plus.google.com/share?url=' + loc + '&t=' + title, 'googlewindow', 'height=450, width=550, top='+($(window).height()/2 - 225) +', left='+$(window).width()/2 +', toolbar=0, location=0, menubar=0, directories=0, scrollbars=0');		
				}
			}
			
		}
	};

})(jQuery);