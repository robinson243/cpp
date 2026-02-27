/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:40:05 by romukena          #+#    #+#             */
/*   Updated: 2026/02/27 16:08:46 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int main() {
    std::cout << "=== EX01 FORM TESTS ===\n\n";
    
    // Test 1: Constructeur Form
    try {
        Form f1("Taxe", 0, 25);   // signGrade invalide
    } catch(std::exception &e) {
        std::cout << "✓ Constructeur signGrade too high: " << e.what() << "\n";
    }
    
    try {
        Form f2("Secret", 151, 25);  // signGrade invalide
    } catch(std::exception &e) {
        std::cout << "✓ Constructeur signGrade too low: " << e.what() << "\n";
    }
    
    Form f_ok("OK", 75, 50);
    std::cout << "✓ Form OK: " << f_ok << "\n";
    
    // Test 2: beSigned() - grades valides
    Bureaucrat boss("Boss", 5);
    Bureaucrat chef("Chef", 70);
    
    std::cout << "\n=== beSigned TESTS ===\n";
    std::cout << "Boss grade: " << boss.getGrade() << "\n";
    std::cout << "Form signGrade: " << f_ok.getSignGrade() << "\n";
    
    f_ok.beSigned(boss);  // 5 <= 75 → OK
    std::cout << "✓ Boss signe OK\n";
    
    try {
        Form f("Test", 75, 50);
        std::cout << "Form OK !" << std::endl;
    } catch(std::exception &e) {
        std::cout << "ERREUR constructeur: " << e.what() << std::endl;
    }
    std::cout << "Form signed: " << (f_ok.getSigned() ? "true" : "false") << "\n";
    
    // Test 3: Grade trop bas
    Bureaucrat noob("Noob", 90);
    try {
        f_ok.beSigned(noob);  // 90 > 75 → EXCEPTION !
        std::cout << "ERREUR: pas d'exception\n";
    } catch(std::exception &e) {
        std::cout << "✓ Noob refusé: " << e.what() << "\n";
    }
    
    return 0;
}
