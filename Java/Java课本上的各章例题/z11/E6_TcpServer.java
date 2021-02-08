package z11;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import javax.swing.*;
public class E6_TcpServer extends JFrame{
	private Container cp;
	private JTextField SentText;
    private JTextArea ReceiveArea;    
    private JScrollPane sp;
    private JPanel p1,p2;   
    private ServerSocket sSocket;
    private Socket cSocket;
    private DataOutputStream dos;
    private DataInputStream dis;    
    E6_TcpServer(){
    	super("服务器程序");
    	cp = this.getContentPane();   	
		SentText = new JTextField(18);
        ReceiveArea = new JTextArea(10,18);
        ReceiveArea.setEditable(false);
        p1 = new JPanel();
        p1.setBorder(BorderFactory.createTitledBorder("接收内容："));		
		p1.add(ReceiveArea);
		sp = new JScrollPane(p1);
		cp.add(sp,BorderLayout.NORTH); 		
		p2 = new JPanel();
        p2.setBorder(BorderFactory.createTitledBorder("发送内容："));		
		p2.add(SentText);	
        cp.add(p2,BorderLayout.SOUTH);              
        SentText.addActionListener(new SentListener());         
        this.setLocation(10,10);
        this.setSize(250, 330);
        this.setResizable(false); // 窗口大小不可调整
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);         
        this.setVisible(true);              
    }
    private void StartServer(){ //启动服务器
    	try {
			sSocket = new ServerSocket(1818);
			cSocket = sSocket.accept();
	        dos = new DataOutputStream(cSocket.getOutputStream());
	        dis = new DataInputStream(cSocket.getInputStream());
	        new Thread(new ReceiveThread()).start();
		} catch (IOException e) {
			e.printStackTrace();
		}		            
    }    
    class ReceiveThread implements Runnable{ 	        
        public void run(){
        	String tempInfo=null; 
            while(true){
                try {                	
                	tempInfo ="客户说: "+ dis.readUTF()+"\n";
    			} catch (IOException e) {
    				e.printStackTrace();
    				System.exit(0);
    			}
                ReceiveArea.append(tempInfo);
                ReceiveArea.setCaretPosition(ReceiveArea.getText().length());//使滚动条滚动到最底端
            }  
        }    
    }    
    class SentListener implements ActionListener{
	    public void actionPerformed(ActionEvent e) {
	    	String tempInfo = SentText.getText().trim();
	        SentText.setText("");
	        try {
	            dos.writeUTF(tempInfo);
	        } catch (IOException e1) {
	            e1.printStackTrace();
	        }
	        ReceiveArea.append("我说: "+tempInfo+"\n");
	        ReceiveArea.setCaretPosition(ReceiveArea.getText().length());
	    }    
    }    
	public static void main(String[] args) {
		E6_TcpServer s=new E6_TcpServer();
		s.StartServer(); 
	}
}