#CheckDesk Embedables Perf Report


## Results Summary

	TYPE			(1)		(2)		(3)
	
	FB COMMENTS		2662ms	2647ms	2332ms
	FB LIKE BTN		1387ms	950ms	1110ms
	TWIT PIC		1096ms	668ms	791ms
	TWIT TWEET		2157ms	2490ms	2832ms
	YOUTUBE VIDEO	1777ms


## Results Details

Facebook comments and Twitter tweets are by far the two worst offenders for overall UI slowdown.  Youtube videos are not very good either.  Facebook like buttons and twitter pictures are generally okay.

Overall, the conclusion is that each every widget added to the page brings a considerable slowdown to the overall page experience.  Adding 20 or 50 of these widgets to each page means an incredibly slow overall page load experience.

There is no way to get around this issue; however, we can use various types of indirection to avoid feeling it all at once.


## Individual Reports

### Facebook - Comments

	LOADING 1 COMMENT
	Run 1: 3000ms
	Run 2: 2510ms
	Run 3: 2540ms
	Run 4: 2600ms
	  Avg: 2662ms
	
	LOADING 2 COMMENTS
	Run 1: 3500ms
	Run 2: 1860ms
	Run 3: 2980ms
	Run 4: 2250ms
	  Avg: 2647ms

	LOADING 3 COMMENTS
	Run 1: 1890ms
	Run 2: 2570ms
	Run 3: 2210ms
	Run 4: 2660ms
	  Avg: 2332ms

### Facebook - Like Buttons

	LOADING 1 LIKE BUTTON
	Run 1: 1530ms
	Run 2: 1300ms
	Run 3: 1090ms
	Run 4: 1630ms
	  Avg: 1387ms
	
	LOADING 2 LIKE BUTTONS
	Run 1: 1070ms
	Run 2: 924ms
	Run 3: 906ms
	Run 4: 902ms
	  Avg: 950ms

	LOADING 3 LIKE BUTTONS
	Run 1: 1020ms
	Run 2: 1140ms
	Run 3: 1080ms
	Run 4: 1200ms
	  Avg: 1110ms



### Twitter - Picture

	LOADING 1 TWITTER PICTURE
	Run 1: 2410ms
	Run 2: 760ms
	Run 3: 452ms
	Run 4: 764ms
	  Avg: 1096ms
	
	LOADING 2 TWITTER PICTURE
	Run 1: 368ms
	Run 2: 880ms
	Run 3: 719ms
	Run 4: 705ms
	  Avg: 668ms

	LOADING 3 TWITTER PICTURE
	Run 1: 921ms
	Run 2: 692ms
	Run 3: 708ms
	Run 4: 843ms
	  Avg: 791ms


### Twitter - Tweet

	LOADING 1 TWITTER TWEET
	Run 1: 3290ms
	Run 2: 1730ms
	Run 3: 1800ms
	Run 4: 1810ms
	  Avg: 2157ms
	
	LOADING 2 TWITTER TWEET
	Run 1: 2160ms
	Run 2: 2160ms
	Run 3: 2050ms
	Run 4: 3590ms
	  Avg: 2490ms

	LOADING 3 TWITTER TWEET
	Run 1: 2420ms
	Run 2: 3590ms
	Run 3: 2310ms
	Run 4: 3009ms
	  Avg: 2832ms

### Youtube - Video

	LOADING 1 YOUTUBE VIDEO
	Run 1: 1690ms
	Run 2: 1930ms
	Run 3: 1660ms
	Run 4: 1830ms
	  Avg: 1777ms
