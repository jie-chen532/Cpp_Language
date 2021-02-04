//ѧ��������ݷ�����
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
		    //���������ַ���
		    String user="sa";//��������Ա�û�,ӵ�ж����������ݶ�������в���Ȩ�� 
			String password="chenjie123.";
			con=DriverManager.getConnection(conStr,user,password);
			//�������ݿ����Ӷ���
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
	
	//����
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
	
	//���ݱ��ɾ��
	public void delNews(String newsNum)
	{
		try {
			/**
			StringBuffer strSql=new StringBuffer();
			strSql.append("delete from News_Table where newsNum='");
			strSql.append(newsNum);
			strSql.append("'");
			Statement st=con.createStatement();
			//����SQL���ִ�ж���
			st.execute(strSql.toString());
			//ִ��SQL���
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
	
	//�޸�
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
			//����SQL���ִ�ж���
			System.out.println(strSql.toString());
			st.execute(strSql.toString());
			//ִ��SQL���
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
		//����SQL���ִ�ж���
		try
		{
		Statement st=con.createStatement();
		ResultSet rs=st.executeQuery(strSql);
		//ִ�в�ѯ��䣬�Ѳ�ѯ�Ľ�����浽�����������
		while(rs.next())//���������л��м�¼
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
	
	
	//���ݱ������ѯѧ����Ϣ
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
		//����SQL���ִ�ж���
		try
		{
		Statement st=con.createStatement();
		ResultSet rs=st.executeQuery(strSql);
		//ִ�в�ѯ��䣬�Ѳ�ѯ�Ľ�����浽�����������
		while(rs.next())//���������л��м�¼
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
		//����SQL���ִ�ж���
		try
		{
		Statement st=con.createStatement();
		ResultSet rs=st.executeQuery(strSql);
		//ִ�в�ѯ��䣬�Ѳ�ѯ�Ľ�����浽�����������
		while(rs.next())//���������л��м�¼
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

