/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.lab10;

import java.util.*;

/**
 *
 * @author navee
 */
public class Lab10 {

    public static void main(String[] args) {
        //Printable Interface
        IPrintable[] printable = {
            new Document(),
            new Image()
        };
        System.out.println("IPrintable Array\n");
        for(IPrintable IP : printable){
            IP.Print();
        }
        
        System.out.println("");
        
        //PaymentProcessor Interface
        List<IPaymentProcessor> Payments = new ArrayList<>();
        
        //credit card objs
        CreditCard c1 = new CreditCard();
        CreditCard c2 = new CreditCard();
        //paypal objs
        PayPal p1 = new PayPal();
        PayPal p2 = new PayPal();
        
        //adding to payments list
        Payments.add(c1);
        Payments.add(p1);
        Payments.add(c2);
        Payments.add(p2);
        
        System.out.println("PaymentProcessor Interface");
        for(IPaymentProcessor payment : Payments){
            payment.ProcessPayment((float) Math.random());
        }
        
        System.out.println("");
        
        //Car with all interfaces
        Car mycar = new Car();
        mycar.ActivateAirbags();
        mycar.CheckBrakes();
        mycar.StartEngine();
        mycar.Drive();
        mycar.Park();
        mycar.StopEngine();
        
    }
}
