#include <iostream>

class cashRegister {
private:
    int cashOnHand;
public:
    cashRegister() : cashOnHand(500) {}
    cashRegister(int cash) : cashOnHand(cash) {}
    
    int getCurrentBalance() {
        return cashOnHand;
    }
    
    void acceptAmount(int amount) {
        cashOnHand += amount;
    }
};

class dispenserType {
private:
    int numberOfItems;
    int ItemCost;
public:
    dispenserType() : numberOfItems(50), ItemCost(0) {}
    dispenserType(int items, int cost) : numberOfItems(items), ItemCost(cost) {}
    
    int getNoOfItems() {
        return numberOfItems;
    }
    
    int getCost() {
        return ItemCost;
    }
    
    void makeSale() {
        numberOfItems--;
    }
};

void showSelection() {
    std::cout << "Меню продуктов:\n";
    std::cout << "1. Конфеты\n";
    std::cout << "2. Чипсы\n";
    std::cout << "3. Жвачка\n";
    std::cout << "4. Печенье\n";
}

void sellProduct(dispenserType& dispenser, cashRegister& reg) {
    int choice;
    std::cout << "Выберите продукт (1-4): ";
    std::cin >> choice;
    
    int cost = 0;
    switch(choice) {
        case 1:
            cost = 10; // Стоимость конфет
            break;
        case 2:
            cost = 15; // Стоимость чипсов
            break;
        case 3:
            cost = 5; // Стоимость жвачки
            break;
        case 4:
            cost = 12; // Стоимость печенья
            break;
        default:
            std::cout << "Некорректный выбор\n";
            return;
    }
    
    std::cout << "Стоимость продукта: " << cost << "\n";
    
    int amount;
    std::cout << "Введите сумму: ";
    std::cin >> amount;
    
    if (amount >= cost) {
        dispenser.makeSale();
        reg.acceptAmount(cost);
        std::cout << "Товар продан. Спасибо!\n";
    } else {
        std::cout << "Недостаточно денег. Пожалуйста, вставьте еще монет.\n";
    }
}

int main() {
    cashRegister reg;
    dispenserType dispenser;
    
    showSelection();
    sellProduct(dispenser, reg);
    
    return 0;
}
