import javax.swing.*;

import java.awt.*;
import java.awt.event.*;



public class Login extends Frame{
    //窗口中的控件
    JLabel userLa,passLa;//文字 用户名和密码
    JTextField userTxt;//文本框 输入用户名
    JPasswordField passTxt;//密码框 输入密码
    JButton loBt,quitBt;//按钮 登录和退出

    private void initControler(){//初始化控件对象

        userLa=new JLabel("用户名");//创建标签
        userLa.setSize(60, 30);
        userLa.setLocation(90, 50);
        this.add(userLa);//将标签放到窗体上

        userTxt=new JTextField();//创建文本框
        userTxt.setSize(150, 30);
        userTxt.setLocation(160, 50);
        this.add(userTxt);//将文本框放到窗体上

        passLa=new JLabel("密   码");//创建标签
        passLa.setSize(60, 30);
        passLa.setLocation(90, 100);
        this.add(passLa);//将标签放到窗体上

        passTxt=new JPasswordField();//创建密码框
        passTxt.setSize(150, 30);
        passTxt.setLocation(160, 100);
        this.add(passTxt);//将密码框放到窗体上

        loBt=new JButton("登录");//创建按钮
        loBt.setSize(60, 30);
        loBt.setLocation(120, 150);
        //loBt.addMouseListener(this);
        this.add(loBt);//将按钮放到窗体上

        quitBt=new JButton("取消");//创建按钮
        quitBt.setSize(60, 30);
        quitBt.setLocation(210, 150);
        //quitBt.addMouseListener(this);
        this.add(quitBt);//将按钮放到窗体上
    }

    public Login(){
        this.setSize(400,250);
        this.setLocation(600,300);
        this.setTitle("新闻信息管理");
        this.setLayout(null);
        initControler();
        this.setVisible(true);//设置窗体可见
    }


}

class MyWindowListener implements WindowListener{//实现窗口监听器

    @Override
    public void windowOpened(WindowEvent e) {

    }

    @Override
    public void windowClosing(WindowEvent e) {
        System.exit(0);
    }

    @Override
    public void windowClosed(WindowEvent e) {

    }

    @Override
    public void windowIconified(WindowEvent e) {

    }

    @Override
    public void windowDeiconified(WindowEvent e) {

    }

    @Override
    public void windowActivated(WindowEvent e) {

    }

    @Override
    public void windowDeactivated(WindowEvent e) {

    }
}


class LoginFailed extends Frame {
    JLabel information;
    JButton retry;

    private void initControler(){//初始化控件对象

        information=new JLabel("输入的用户名和密码有误，请重新输入");//创建标签
        information.setSize(300, 30);
        information.setLocation(90, 50);
        this.add(information);

    }
    public LoginFailed(){
        this.setSize(400,250);
        this.setLocation(600,300);
        this.setTitle("新闻信息管理");
        this.setLayout(null);
        initControler();
        this.setVisible(true);
    }
}

class Signin1 {
    Login signin;
    public Signin1(final Login signin){
        this.signin=signin;
        MyWindowListener mwl=new MyWindowListener();
        this.signin.addWindowListener(mwl);
        this.signin.loBt.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String name=signin.userTxt.getText().trim();
                //获取用户名
                String pass=signin.passTxt.getText().trim();
                //获取密码
                String defaultUser="zuo";
                String defaultPass="123456";
                if(name.equals(defaultUser)&&pass.equals(defaultPass)){
                    //System.out.println("登录成功");
                    //这里需要一个方法
                    signin.setVisible(false);
                    Main m=new Main();
                }else{
                    //System.out.println("登陆失败");
                    //这里需要一个方法
                    signin.setVisible(false);
                    LoginFailed1 lf=new LoginFailed1(new LoginFailed());
                }
            }
        });
        this.signin.quitBt.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
    }
}



class LoginFailed1 {
    LoginFailed loginFailed;
    public LoginFailed1(final LoginFailed loginFailed){
        this.loginFailed=loginFailed;
        MyWindowListener mwl=new MyWindowListener();
        this.loginFailed.addWindowListener(mwl);
        this.loginFailed.retry.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
            	loginFailed.setVisible(false);
                Signin1 signin1=new Signin1(new Login());
            }
        });
    }
}

    





