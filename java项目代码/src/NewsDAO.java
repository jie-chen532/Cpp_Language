//学生表的数据访问类
import java.util.*;
import java.sql.*;
public class NewsDAO 
{
	private Connection con;
	
	public NewsDAO()
	{
		try {
			Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
		    String conStr="jdbc:sqlserver://localhost:1433; DatabaseName=NewsManger";
		    //配置连接字符串
		    String user="sa";//超级管理员用户,拥有对于所有数据对象的所有操作权限 
			String password="chenjie123.";
			con=DriverManager.getConnection(conStr,user,password);
			//创建数据库连接对象
		}
		catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		catch(SQLException ex)
		{
			System.out.println(ex.toString());
		}
	}
	
	//插入
	public void addNews(NewsInfo news)
	{
		try {
			PreparedStatement ps;
			ps=con.prepareStatement("insert into News_Table  values(?,?,?,?)");
			ps.setString(1, news.newsNum);
			ps.setString(2, news.newsName);
			ps.setString(3, news.newsContent);
			ps.setString(4, news.newsDate);
			ps.execute();
			//con.close(); 	
		} 	
		catch(SQLException ex)
		{
			System.out.println(ex.toString());
		}
	}
	
	//根据编号删除
	public void delNews(String newsNum)
	{
		try {
			/**
			StringBuffer strSql=new StringBuffer();
			strSql.append("delete from News_Table where newsNum='");
			strSql.append(newsNum);
			strSql.append("'");
			Statement st=con.createStatement();
			//创建SQL语句执行对象
			st.execute(strSql.toString());
			//执行SQL语句
			st.close();
			con.close();
			**/
			PreparedStatement ps;
			ps=con.prepareStatement("delete from News_Table where newsNum=?");
			ps.setString(1, newsNum);
			ps.execute();
			ps.close();
		} 
		catch(SQLException ex)
		{
			System.out.println(ex.toString());
		}
	}
	
	//修改
	public void updateNews(NewsInfo news)
	{
		try {
			StringBuffer strSql=new StringBuffer();
			strSql.append("update News_Table set newsName='");
			strSql.append(news.newsName);
			strSql.append("', newsContent='");
			strSql.append(news.newsContent);
			strSql.append("', newsDate='");
			strSql.append(news.newsDate);
			strSql.append("' where newsNum='");
			strSql.append(news.newsNum);
			strSql.append("'");
			Statement st=con.createStatement();
			//创建SQL语句执行对象
			System.out.println(strSql.toString());
			st.execute(strSql.toString());
			//执行SQL语句
			st.close();
		} 
		catch(SQLException ex)
		{
			System.out.println(ex.toString());
		}
	}
	

	public void addNew(NewsInfo[] news)
	{
		if(news!=null)
		{
			if(news.length>0)
			{
				for(int i=0;i<news.length;i++)
				{
					addNews(news[i]);
				}
			}
		}
	}
	
	public void delNew(String[] newsNum)
	{
		if(newsNum!=null)
		{
			if(newsNum.length>0)
			{
				for(int i=0;i<newsNum.length;i++)
				{
					delNews(newsNum[i]);
				}
			}
		}
	}
	
	public void updateNew(NewsInfo[] news)
	{
		if(news!=null)
		{
			if(news.length>0)
			{
				for(int i=0;i<news.length;i++)
				{
					updateNews(news[i]);
				}
			}
		}
	}
	
	public NewsInfo[] findAllNews()
	{
		ArrayList<NewsInfo> news=new ArrayList<NewsInfo>();
		String strSql="select * from News_Table";
		//创建SQL语句执行对象
		try
		{
		Statement st=con.createStatement();
		ResultSet rs=st.executeQuery(strSql);
		//执行查询语句，把查询的结果保存到结果集对象中
		while(rs.next())//如果结果集中还有记录
		{
			String num=rs.getString(1);
			String name=rs.getString(2);
			String content=rs.getString(3);
			String date=rs.getString(4);
			NewsInfo newss=new NewsInfo(num,name,content,date);
			news.add(newss);
		}
		rs.close();
		st.close();
		}
		catch(SQLException ex)
		{
			
		}
		return (NewsInfo[])news.toArray(new NewsInfo[news.size()]);
	}
	
	
	//根据编号来查询学生信息
	public NewsInfo findNewsByNum(String newsNum)
	{
		String strSql="select * from News_Table where newsNum='"+newsNum+"' ";
		NewsInfo result=null;
		try
		{
			Statement st=con.createStatement();
			ResultSet rs=st.executeQuery(strSql.toString());
			if(rs.next())
			{
				String num=rs.getString(1);
				String name=rs.getString(2);
				String content=rs.getString(3);
				String date=rs.getString(4);
				result=new NewsInfo(num,name,content,date);
			}
		}
		catch(SQLException ex)
		{
			System.out.println(ex.toString());
		}
		return result;
	}
	
	public NewsInfo[] findNewsByName(String newsName)
	{
		ArrayList<NewsInfo> news=new ArrayList<NewsInfo>();
		String strSql="select * from News_Table where newsName like '%"+newsName+"%' ";
		//创建SQL语句执行对象
		try
		{
		Statement st=con.createStatement();
		ResultSet rs=st.executeQuery(strSql);
		//执行查询语句，把查询的结果保存到结果集对象中
		while(rs.next())//如果结果集中还有记录
		{
			String num=rs.getString(1);
			String name=rs.getString(2);
			String content=rs.getString(3);
			String date=rs.getString(4);
			NewsInfo newss=new NewsInfo(num,name,content,date);
			news.add(newss);
		}
		rs.close();
		st.close();
		}
		catch(SQLException ex)
		{
			
		}
		return (NewsInfo[])news.toArray(new NewsInfo[news.size()]);
	}
	
	public NewsInfo[] findNewsByDate(String newsDate)
	{
		ArrayList<NewsInfo> news=new ArrayList<NewsInfo>();
		String strSql="select * from News_Table where newsDate='"+newsDate+"' ";
		//创建SQL语句执行对象
		try
		{
		Statement st=con.createStatement();
		ResultSet rs=st.executeQuery(strSql);
		//执行查询语句，把查询的结果保存到结果集对象中
		while(rs.next())//如果结果集中还有记录
		{
			String num=rs.getString(1);
			String name=rs.getString(2);
			String content=rs.getString(3);
			String date=rs.getString(4);
			NewsInfo newss=new NewsInfo(num,name,content,date);
			news.add(newss);
		}
		rs.close();
		st.close();
		}
		catch(SQLException ex)
		{
			
		}
		return (NewsInfo[])news.toArray(new NewsInfo[news.size()]);
	}
}

