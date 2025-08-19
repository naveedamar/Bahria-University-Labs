/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.finals;

/**
 *
 * @author navee
 */
class ItalianMeal extends AbstractMeal {
    private String customization;

    public ItalianMeal(String dishType, String customization) {
        super(dishType, (dishType.equalsIgnoreCase("Pasta") ? 14.0 : 18.0));
        this.customization = customization;
        System.out.println("New Italian Meal: " + getDetails() + " ready.");
    }

    @Override
    public void prepare() {
        super.prepare();
        System.out.println("Cooking " + getName() + " with " + customization + " (Italian style).");
    }

    @Override
    public String getDetails() { return getName() + " (" + customization + ")"; }
}
