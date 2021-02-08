package z11;
import java.net.*;
public class E3_InetAddressTest {
	public static void main(String[] args) throws UnknownHostException {
		InetAddress SguAddress = InetAddress.getByName("www.sgu.edu.cn");
		InetAddress MyAddress=InetAddress.getLocalHost();
        System.out.println( "Sgu的InetAddress：" + SguAddress );
        System.out.println( "My的InetAddress：" + MyAddress );
        System.out.println( "Sgu的计算机名：" + SguAddress.getHostName() );
        System.out.println( "Sgu的IP地址：" + SguAddress.getHostAddress() );
	}
}