package shopping;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

public class SQLUtil {
	static String driver, url, user, pass, sql;
	static Connection ct 		= null;
	static Statement st			= null;
	static PreparedStatement ps = null;
	static ResultSet rs 		= null;
	
	public SQLUtil() {
		// 初始化连接数据库字符串
		driver = "org.mariadb.jdbc.Driver";
		url    = "jdbc:mariadb://localhost:3306/shopping?characterEncoding=utf8";
		user   = "root";
		pass   = "*Dxj1003746818";
	}
	
	public void addTheIdGift(user u, int giftId) {
		//添加用户礼物
		try {
			int usergiftId = getLastId("usergift") + 1;
			Class.forName(driver);
			sql = "insert into usergift values(?, ?, ?)";
			ct  = DriverManager.getConnection(url, user, pass);
			ps  = ct.prepareStatement(sql);
			ps.setLong(1, usergiftId);
			ps.setLong(2, u.id);
			ps.setLong(3, giftId);
			ps.executeUpdate();
			ps.close();
			ct.close();
		}catch (Exception e) {}
	}
	
	public void addOrderDetail(user u,ArrayList<product> choose) {
		//添加详细订单
		try {
			int orderId = getLastId("orders");
			sql = "insert into orderdetail values (?, ?, ?, ?)";
			
			Class.forName(driver);
			ct  = DriverManager.getConnection(url, user, pass);
			ps  = ct.prepareStatement(sql);
			for(product p : choose) {
				int orderdetailId = getLastId("orderdetail") + 1;
				ps.setLong(1, orderdetailId);
				ps.setLong(2, orderId);
				ps.setLong(3, p.goodId);
				ps.setLong(4, p.number);
				ps.executeUpdate();
			}
			ps.close();
			ct.close();
		}catch(Exception e) {
			System.out.println("出错了-3.1");
			System.out.println(e);
		}
	}
	
	
	public void addOrder(user u) {
		//添加订单
			try {
				int orderId = getLastId("orders") + 1; 
				int money   = 100;
				sql			= "insert into orders values(" + orderId + ", " + u.id + ", " + money + ", now(), 1)";
				
				Class.forName(driver);
				ct   	    = DriverManager.getConnection(url, user, pass);
				st 			= ct.createStatement();
				st.executeUpdate(sql);
				st.close();
				ct.close();
			}catch(Exception e) {
				System.out.println("出错了-3");
				System.out.println(e);
			}
	}
	
	public ArrayList<usergift> getUserGifts(user u){
		//获取用户礼物列表
		ArrayList<usergift> usergifts = new ArrayList<usergift>();
		try {
			Class.forName(driver);
			sql = "select giftName, price worth from usergift, gift where usergift.giftId = gift.id and usergift.userId = " + u.id;
			ct  = DriverManager.getConnection(url, user, pass);
			st  = ct.createStatement();
			rs  = st.executeQuery(sql);
			while(rs.next()) {
				usergift ug   	  = new usergift();
				ug.giftNameString = rs.getString(1);
				ug.worth          = rs.getFloat(2);
				usergifts.add(ug);
			}
		}catch(Exception e) {}
		return usergifts;
	}
	
	public void updateUserPassword(user u) {
		//更新用户密码
		try {
			Class.forName(driver);
			sql = "update users set loginPwd = ? where id = ?";
			ct  = DriverManager.getConnection(url, user, pass);
			ps  = ct.prepareStatement(sql);
			ps.setString(1, u.loginPwd);
			ps.setLong(2, u.id);
			ps.executeUpdate();
			ps.close();
			ct.close();
		}catch(Exception e) {
			System.out.println("出错了-2");
		}
	}
	
	public int getLastId(String table) {
		//获取表中最后一行的Id值
		int id  = 0;
		try {
			Class.forName(driver);
			sql = "select * from " + table;
			ct  = DriverManager.getConnection(url, user, pass);
			st  = ct.createStatement();
			rs  = st.executeQuery(sql);
			rs.last();
			id  = rs.getInt(1);
			rs.close();
			st.close();
			ct.close();
		}catch(Exception e) {}
		return id;
	}
	
	public 	ArrayList<gift> getGifts(){
		//获取礼物列表
		ArrayList<gift> gifts = new ArrayList<gift>();
		try {
			Class.forName(driver);
			sql = "select * from gift";
			ct  = DriverManager.getConnection(url, user, pass);
			st  = ct.createStatement();
			rs  = st.executeQuery(sql);
			while(rs.next()) {
				gift g 	   = new gift();
				g.id 	   = rs.getInt(1);
				g.giftName = rs.getString(2);
				g.price    = rs.getFloat(3);
				gifts.add(g);
			}
			rs.close();
			st.close();
			ct.close();
		}catch(Exception e) {}
		return gifts;
	}
	
	public ArrayList<good> getGoods(){
		//获取货物列表
		ArrayList<good> goods = new ArrayList<good>();
		try {
			Class.forName(driver);
			sql = "select * from goods";
			ct  = DriverManager.getConnection(url, user, pass);
			st  = ct.createStatement();
			rs  = st.executeQuery(sql);
			while(rs.next()) {
				good g 		= new good();
				g.id 		= rs.getInt(1);
				g.goodsName = rs.getString(2);
				g.prodArea  = rs.getString(3);
				g.spec 		= rs.getString(4);
				g.price 	= rs.getFloat(5);
				goods.add(g);
			}
			rs.close();
			st.close();
			ct.close();
		}catch(Exception e) {
			System.out.println("出错了-4");
		}
		return goods;
	}
	
	public user login(String u, String p) {
		//返回登录用户的用户信息
		user  usr = new user();
		usr.realName = "#";
		try {
			Class.forName(driver);
			sql = "select * from users";
			ct  = DriverManager.getConnection(url, user, pass);
			st  = ct.createStatement();
			rs  = st.executeQuery(sql);
			while(rs.next()) {
				if(u.equals(rs.getString(2))&&p.equals(rs.getString(3))){
					usr.id 		 = rs.getInt(1);
					usr.loginId  = rs.getString(2);
					usr.loginPwd = rs.getString(3);
					usr.realName = rs.getString(4);
					usr.score 	 = rs.getFloat(5);
					break;
				}
			}
			rs.close();
			st.close();
			ct.close();
		}catch(Exception e) {
			System.out.println("出错了-1");
		}
		return usr;
	}
	
	public ArrayList<userData> getUserDatas(user u){
		//获取用户的订单信息
		ArrayList<userData> userDatas = new ArrayList<userData>();
		try{
			Class.forName(driver);
			sql = "select a.total_orders, orderdetail.orderId,realName, total total_money, addDate, isPlay, goodsName, price, number, price*number total_price from orders,users,orderdetail,goods, (select count(userId) total_orders, userId from orders group by userId) a where  orderdetail.orderId = orders.id and orders.userId = users.id and orderdetail.goodsId = goods.id and orders.userId = a.userId;";
			ct  = DriverManager.getConnection(url,user,pass);
			st  = ct.createStatement();
			rs  = st.executeQuery(sql);
			//System.out.println("默认管理员ID：" + u.id);
			while(rs.next()){
				if(u.realName.equals(rs.getString(3))) {
					userData usr     = new userData();
					usr.total_orders = rs.getInt(1);
					usr.orderId      = rs.getInt(2);
					usr.realName     = rs.getString(3);
					usr.total_money  = rs.getFloat(4);
					usr.addDate      = rs.getString(5);
					usr.isPlay       = rs.getInt(6);
					usr.goodsName    = rs.getString(7);
					usr.price        = rs.getFloat(8);
					usr.number       = rs.getInt(9);
					usr.total_price  = rs.getFloat(10);
					userDatas.add(usr);
				}
			}
			rs.close();
			st.close();
			ct.close();
		}catch(Exception e){}
		return userDatas;
	}
	
	/*void Connect() {
		try {
			//连接数据库并输出数据
			Class.forName(driver);
			ct = DriverManager.getConnection(url, user, pass);
			ps = ct.prepareStatement(sql);
			rs = ps.executeQuery(); 
			while(rs.next()) {
				System.out.println(rs.getInt(1) + " " + rs.getString(2) + " " + rs.getString(3));
			}
			rs.close();
			ps.close();
			ct.close();
		} catch (Exception e) {
			System.out.println(e);
		}
	}*/
	
	/*public static void main(String[] args) {
		SQLUtil sql=new SQLUtil();
		//ArrayList<userData> userDatas = sql.getUserDatas();
		//for(userData usr : userDatas){
		//	System.out.println(usr.total_orders + " " + usr.orderId + " " + usr.realName + " " + usr.total_money + " " + usr.addDate + " " + usr.isPlay + " " + usr.goodsName + " " + usr.price + " " + usr.number + " " + usr.total_price);
		//}
		System.out.println(sql.getLastId("goods"));

	}*/

}





class usergift{
	public int total_gift;
	public String giftNameString;
	public float worth;
}

class userData{
	public int total_orders, orderId, isPlay, number;
	public String realName, addDate,  goodsName;
	public float total_money, price, total_price;
}

class good{
	public int id;
	public String goodsName, prodArea, spec;
	public float price;
}

class  user{
	public int id;
	public String loginId, loginPwd, realName;
	public float score;
}

class gift{
	public int id;
	public String giftName;
	public float price;
}

class product{
	public int goodId, number;
}