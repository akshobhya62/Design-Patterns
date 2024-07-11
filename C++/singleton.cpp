
// Thread-Safe Singleton Using Static Local Variable (Meyers' Singleton)

#include <iostream>

class Singleton {
public:
    // Public static method to access the instance
    static Singleton* getInstance() {
        static Singleton instance; // Guaranteed to be initialized only once
        return &instance;
    }

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    // Private constructor to prevent instantiation
    Singleton() {}
};

int main() {
    // Example usage
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    std::cout << (s1 == s2) << std::endl;  // Output should be 1 (true)
    return 0;
}



/*
 // Lazy Initialization with Mutex (Thread-Safe Singleton using a Mutex)
 #include <iostream>
#include <mutex>

class Singleton {
public:
    // Public static method to access the instance
    static Singleton* getInstance() {
        if (!instance) {
            std::lock_guard<std::mutex> guard(mutex);
            if (!instance) {
                instance = new Singleton();
            }
        }
        return instance;
    }

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    // Private constructor to prevent instantiation
    Singleton() {}

    // Static pointer to hold the Singleton instance
    static Singleton* instance;
    // Mutex for thread safety
    static std::mutex mutex;
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mutex;

int main() {
    // Example usage
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    std::cout << (s1 == s2) << std::endl;  // Output should be 1 (true)
    return 0;
}

*/


/*
// Thread-Safe Singleton Using std::call_once
#include <iostream>
#include <mutex>

class Singleton {
public:
    // Public static method to access the instance
    static Singleton* getInstance() {
        std::call_once(initFlag, []() {
            instance.reset(new Singleton());
        });
        return instance.get();
    }

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    // Private constructor to prevent instantiation
    Singleton() {}

    // Static unique_ptr to hold the Singleton instance
    static std::unique_ptr<Singleton> instance;
    // Static once_flag to ensure initialization happens only once
    static std::once_flag initFlag;
};

// Initialize static members
std::unique_ptr<Singleton> Singleton::instance;
std::once_flag Singleton::initFlag;

int main() {
    // Example usage
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    std::cout << (s1 == s2) << std::endl;  // Output should be 1 (true)
    return 0;
}

*/

/*
// Thread-Safe Singleton Using Double-Checked Locking
#include <iostream>
#include <atomic>

class Singleton {
public:
    // Public static method to access the instance
    static Singleton* getInstance() {
        Singleton* temp = instance.load(std::memory_order_acquire);
        if (!temp) {
            std::lock_guard<std::mutex> guard(mutex);
            temp = instance.load(std::memory_order_relaxed);
            if (!temp) {
                temp = new Singleton();
                instance.store(temp, std::memory_order_release);
            }
        }
        return temp;
    }

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    // Private constructor to prevent instantiation
    Singleton() {}

    // Static atomic pointer to hold the Singleton instance
    static std::atomic<Singleton*> instance;
    // Mutex for thread safety
    static std::mutex mutex;
};

// Initialize static members
std::atomic<Singleton*> Singleton::instance{ nullptr };
std::mutex Singleton::mutex;

int main() {
    // Example usage
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    std::cout << (s1 == s2) << std::endl;  // Output should be 1 (true)
    return 0;
}

*/
