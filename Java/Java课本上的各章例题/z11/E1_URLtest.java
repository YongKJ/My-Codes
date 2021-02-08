package z11;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
public class E1_URLtest {	
	public static void main(String[] args) {
		URL url = null;
       	try{
            url = new URL("http://download.csdn.net/detail/cflynn/9500077");
       	}
       	catch(MalformedURLException e){
            System.out.println("MalformedURLException: "+ e);
       	}
        System.out.println("The URL is:"+url);
       	System.out.println("Protocol is: "+url.getProtocol());
       	System.out.println("Host is: "+url.getHost());
       	System.out.println("Port is: "+url.getPort());
       	System.out.println("Path is: "+url.getPath());
       	System.out.println("File is: "+url.getFile());
       	try {
			System.out.println("openConnection() is: "+url.openConnection());			
		} catch (IOException e) {			
			e.printStackTrace();
		}
	}
}