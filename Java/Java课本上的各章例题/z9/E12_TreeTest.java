package z9;
import java.awt.Container;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.tree.DefaultMutableTreeNode;
public class E12_TreeTest implements TreeSelectionListener{
	final JTree tree;
	JTextArea text=new JTextArea(10,10);
	E12_TreeTest(){
		JFrame f = new JFrame ("Tree测试");
		Container cp = f.getContentPane();
		DefaultMutableTreeNode top =new DefaultMutableTreeNode("韶关大学"); 
		DefaultMutableTreeNode node1 = null,node2 = null,tempNode = null;		
		node1 = new DefaultMutableTreeNode("信息科学与工程学院");
		tempNode =new DefaultMutableTreeNode("计算机科学与技术");
		node1.add(tempNode);
		tempNode =new DefaultMutableTreeNode("通信工程");
		node1.add(tempNode);
		tempNode =new DefaultMutableTreeNode("信息管理与信息系统");
		node1.add(tempNode);
		top.add(node1);				
		node2 = new DefaultMutableTreeNode("英东生物工程学院");
		tempNode =new DefaultMutableTreeNode("生物技术");
		node2.add(tempNode);
		tempNode =new DefaultMutableTreeNode("食品科学与工程");
		node2.add(tempNode);
		top.add(node2);		
		tree = new JTree(top);
		tree.addTreeSelectionListener(this);		
		JScrollPane treeView = new JScrollPane(tree);
		JScrollPane scrollpane=new JScrollPane(text);
		JSplitPane splitpane=new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,true,treeView,scrollpane); //分割面版
		splitpane.setDividerLocation(200);     //设置splitpane的分隔线位置
		splitpane.setOneTouchExpandable(true); //设置splitpane可以展开或收起		
		cp.add(splitpane);
		f.setSize(420,200);
		f.setVisible(true);	
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}	
	public void valueChanged(TreeSelectionEvent e) {
		if(e.getSource()==tree) 
        { 
			DefaultMutableTreeNode node = (DefaultMutableTreeNode) tree.getLastSelectedPathComponent();
			if (node == null) return;
			if (node.isLeaf()) {
				Object object = node.getUserObject();
				text.setText("你选择了：" + object.toString()); 
			}
        }				
	}
	public static void main(String[] args) {
		new E12_TreeTest();
	}
}