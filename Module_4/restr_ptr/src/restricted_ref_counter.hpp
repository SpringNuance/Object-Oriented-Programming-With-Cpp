#ifndef AALTO_ELEC_CPP_COUNTER_CLASS
#define AALTO_ELEC_CPP_COUNTER_CLASS

// implement a reference counter helper class if you want to

class restrictedRefCounter {
    public:
    // Constructor
        restrictedRefCounter(): count(1) {};
   
    // Disallowing copy and assign counter
        restrictedRefCounter(const restrictedRefCounter&) = delete;
        restrictedRefCounter& operator=(const restrictedRefCounter&) = delete;
    
        
    // Destructor
        ~restrictedRefCounter(){};

        int getCounter(){
            return count;
        }

        void IncrementCount(){ count++ ; }
        void DecrementCount(){ count-- ; }
     
    private:
        int count{}; 
};

#endif