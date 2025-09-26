/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.finals;

/**
 *
 * @author navee
 */
class AsianMeal extends AbstractMeal {

    private int portions;

    public AsianMeal(String dishType, int portions) {
        super(dishType, (dishType.equalsIgnoreCase("Sushi") ? 15.0 : 12.0) * portions);
        this.portions = portions;
        System.out.println("New Asian Meal: " + getDetails() + " ready.");
    }

    @Override
    public void prepare() {
        super.prepare();
        System.out.println("Adding  Asian touches for " + getName() + " (" + portions + " portions).");
    }

    @Override
    public String getDetails() {
        return getName() + " (" + portions + " portions)";
    }
}
