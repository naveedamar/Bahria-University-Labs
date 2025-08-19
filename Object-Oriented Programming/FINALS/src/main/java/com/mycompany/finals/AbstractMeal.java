/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.finals;

/**
 *
 * @author navee
 */
abstract class AbstractMeal implements MEAL {

    protected String name;
    protected double finalPrice;

    public AbstractMeal(String name, double basePrice) {
        this.name = name;
        this.finalPrice = basePrice;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public double getPrice() {
        return finalPrice;
    }

    @Override
    public void prepare() {
        System.out.println("Preparing " + name + "...");
    }

    @Override
    public abstract String getDetails();
}
