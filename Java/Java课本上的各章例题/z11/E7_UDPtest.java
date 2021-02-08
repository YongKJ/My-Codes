package z11;
import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import java.net.*;
import javax.swing.*;
public class E7_UDPtest extends JFrame{
	private Container cp;
	private JLabel outlb,inlb;
	private JTextField outPort;
	private JTextField SentText;	
    private JTextArea ReceiveArea;    
    private JScrollPane sp;
    private JPanel p0,p1,p2; 
    private DatagramSocket datagramSocket;    
    E7_UDPtest(){
    	super("UDP聊天程序测试");
    	cp = this.getContentPane(); 
    	inlb=new JLabel("接收端口：1010");
    	outlb=new JLabel("发送端口：");    	
    	outPort = new JTextField(5);
    	outPort.setText("1020");    	
		SentText = new JTextField(20);	
        ReceiveArea = new JTextArea(10,20);
        ReceiveArea.setEditable(false);
        p0 = new JPanel(new FlowLayout(FlowLayout.LEFT));
        p0.setBorder(BorderFactory.createTitledBorder("端口信息："));
        p0.add(outlb);
        p0.add(outPort);
        p0.add(inlb);
        cp.add(p0,BorderLayout.NORTH); 	        
        p1 = new JPanel();
        p1.setBorder(BorderFactory.createTitledBorder("接收内容："));		
		p1.add(ReceiveArea);
		sp = new JScrollPane(p1);
		cp.add(sp,BorderLayout.CENTER); 		
		p2 = new JPanel();
        p2.setBorder(BorderFactory.createTitledBorder("发送内容："));				
		p2.add(SentText);
        cp.add(p2,BorderLayout.SOUTH);              
        SentText.addActionListener(new SentListener());         
        this.setLocation(10,10);
        this.pack();
        this.setResizable(false); // 窗口大小不可调整
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);         
        this.setVisible(true);
    }  
    class ReceiveThread implements Runnable {   	
		public void run() {
			DatagramPacket dp;
			int port=1010;
			try {
				port = Integer.parseInt(JOptionPane.showInputDialog(null,"请输入接收端口号:",JOptionPane.QUESTION_MESSAGE));
				if (port < 1 || port > 65535) {
					throw new RuntimeException("端口号超出范围");
				}
				inlb.setText("接收端口："+port);
				datagramSocket = new DatagramSocket(port);				
			} catch (SocketException e1) {
				e1.printStackTrace();
			}
	    	byte[] buf = new byte[1024];
	    	dp = new DatagramPacket(buf, buf.length);	    	
			String tempInfo=null; 
            while(!datagramSocket.isClosed()){
            	try {
					datagramSocket.receive(dp); // 接收聊天消息
				} catch (IOException e) {
					e.printStackTrace();
				} 
            	tempInfo ="对方说: "+ new String(dp.getData(), 0,dp.getLength())+"\n";
            	ReceiveArea.append(tempInfo);
                ReceiveArea.setCaretPosition(ReceiveArea.getText().length());//使滚动条滚动到最底端
            }			
		}     	
    } 
    class SentListener implements ActionListener{
		public void actionPerformed(ActionEvent arg0) {
			int port=1020;
			port = Integer.parseInt(outPort.getText().trim());
			if (port < 1 || port > 65535) {
				throw new RuntimeException("端口号超出范围");
			}
			String tempInfo = SentText.getText().trim();
			byte[] buf = tempInfo.getBytes();
			SentText.setText("");		
			try {
				DatagramPacket dp=new DatagramPacket(buf,buf.length,InetAddress.getByName("127.0.0.1"), port);
				datagramSocket.send(dp);  // 发送聊天消息
			} catch (UnknownHostException e) {
				e.printStackTrace();
			} catch (IOException e) {
				e.printStackTrace();
			}
			ReceiveArea.append("我说: "+tempInfo+"\n");
	        ReceiveArea.setCaretPosition(ReceiveArea.getText().length());
		}
    	
    }  
	public static void main(String[] args) {
		E7_UDPtest u=new E7_UDPtest();
		ReceiveThread Receive=u.new ReceiveThread();
		new Thread(Receive).start();
	}
}