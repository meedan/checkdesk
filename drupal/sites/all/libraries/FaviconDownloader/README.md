FaviconDownloader
-----------------
FaviconDownloader can find favicon URL (and download it) from a web page URL. This PHP class handles multiple favicons flavors, including some edge cases like relative URL or embed favicons :

* Absolute URL :  
  `<link rel="shortcut icon" href="http://www.domain.com/images/fav.ico" />`
* Absolute URL with relative scheme :  
  `<link rel="shortcut icon" href="//www.domain.com/images/fav.ico" />`
* Absolute path :  
  `<link rel="shortcut icon" href="/images/fav.ico" />`
* Relative URL :  
  `<link rel="shortcut icon" href="../images/fav.ico" />`
* Embed base64-encoded favicon :  
  `<link rel="icon" type="image/x-icon" href="data:image/x-icon;base64,AAABAAEAE ... /wAA//8AAA==" />`
  
### Install
The easiest way to install FaviconDownloader is to use Composer from the command line :

```
composer require vincepare/favicon-downloader
```

Otherwise, just download [FaviconDownloader.php](https://raw.githubusercontent.com/vincepare/FaviconDownloader/master/src/FaviconDownloader.php) and require it manually. Tested on PHP 5.3, 5.4, 5.5 & 5.6.

### Example
```php
require 'FaviconDownloader.php';
use Vincepare\FaviconDownloader\FaviconDownloader;

// Find & download favicon
$favicon = new FaviconDownloader('http://stackoverflow.com/questions/19503326/bug-with-chrome-tabs-create-in-a-loop');

if (!$favicon->icoExists) {
    echo "No favicon for ".$favicon->url;
    die(1);
}

echo "Favicon found : ".$favicon->icoUrl."\n";

// Saving favicon to file
$filename = dirname(__FILE__).DIRECTORY_SEPARATOR.'favicon-'.time().'.'.$favicon->icoType;
file_put_contents($filename, $favicon->icoData);
echo "Saved to ".$filename."\n\n";

echo "Details :\n";
$favicon->debug();
```