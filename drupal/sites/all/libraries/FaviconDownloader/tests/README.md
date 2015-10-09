You need Fiddler in order to run this test suite. Fiddler is a web debugging proxy which comes with plenty of useful features, like the autoresponder. The autoresponder can mimic web server response using previously saved responses, and this is used in this test case.

So before executing phpunit, take care to have fiddler running with autoresponder enabled :

 1. Download fiddler at http://www.telerik.com/download/fiddler, install it and launch it*
 2. Go to **Tools > Fiddler Options**
    * In the **HTTPS** tab, enable *Capture HTTPS CONNECTs* and *Decrypt HTTPS traffic*
    * In the **Connections** tab, enable *Allow remote computers to connect*
 3. In the right pane, click the **AutoResponder** tab, click *Import...* and choose `autoresponder-session.saz` (available in the `tests/Fixtures` directory of this repository). You can also simply drag & drop the saz file into the AutoResponder tab if you're a 21st century geek ;)
 4. Check **Enable automatic responses** in the *AutoResponder* tab

Now fiddler is ready and you can run phpunit. Fiddler is expected to run at `localhost:8888` but you can change it by creating your own `phpunit.xml`.

*Fiddler only works on Windows. If you're on Linux, the easiest way to get fiddler working is to run it on a windows virtual machine.