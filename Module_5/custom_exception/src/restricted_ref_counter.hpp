// copy your implementation from the last round here (if you had one and used it)
// and wrap it inside a WeirdMemoryAllocator namespace

#ifndef AALTO_ELEC_CPP_COUNTER_CLASS
#define AALTO_ELEC_CPP_COUNTER_CLASS

// implement a reference counter helper class if you want to
namespace WeirdMemoryAllocator {
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
}


#endif