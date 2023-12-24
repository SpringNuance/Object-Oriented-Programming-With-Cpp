#include "transcript.hpp"

/* TODO: class TranscriptRegistry
 * ------------
 * Description:
 * A class for storing and interfacing with transcripts (type Transcript).
 * ------------
 * Functions:
 *
 * Add: the function returns nothing and takes a const reference to Transcript as a 
 * parameter. Adds the transcript to the registry.
 *
 * RemoveById: takes takes a student id as a const reference to string as 
 * parameter and returns nothing. Removes all transcripts with the given student id.
 * 
 * FindTranscript: takes a student id as a const reference to string as a parameter
 * and returns an iterator to the first transcript with the given student id.
 * 
 * FindCourseResults: takes a course name as a const reference to string as a parameter
 * and returns a list of pairs of student ids and course grades for the given course 
 * from the registry.
 * 
 * GetTranscripts: takes no parameters and returns a container that supports begin and end
 * functions containing all the transcripts in the registry, in the order they were added.
 * ------------
 * Other:
 * As like always, any function that doesn't directly or indirectly modify the object
 * should by const.
 * 
 * Hint: due to the GetTranscripts function it would be beneficial to use e.g. list or
 * vector to store the transcripts.
*/

// Add: the function returns nothing and takes a const reference to Transcript as a 
// parameter. Adds the transcript to the registry.
void TranscriptRegistry::Add(const Transcript& transcript){
   transcripts.push_back(transcript);
}

// RemoveById: takes a student id as a const reference to string as 
// parameter and returns nothing. Removes all transcripts with the given student id.
void TranscriptRegistry::RemoveById(const std::string& studentID){
    transcripts.erase(std::remove_if(transcripts.begin(), transcripts.end(),
                        [=](Transcript& trans) -> bool { 
                            return trans.student_id == studentID;
                        }),
                transcripts.end());
}

// FindTranscript: takes a student id as a const reference to string as a parameter
// and returns an iterator to the first transcript with the given student id.
std::list<Transcript>::const_iterator TranscriptRegistry::FindTranscript(const std::string& studentID) const {
    auto ptr = transcripts.begin();
    for (; ptr != transcripts.end(); ptr++){
        if ((*ptr).student_id == studentID){
            break;
        }    
    }
    return ptr;
    /*auto it = std::find_if(transcripts.begin(), transcripts.end(),
            [=](Transcript trans) -> bool { 
                return trans.name == studentID; 
            });
    return it;*/
}

// FindCourseResults: takes a course name as a const reference to string as a parameter
// and returns a list of pairs of student ids and course grades for the given course 
// from the registry.
std::list<std::pair<std::string, size_t>> TranscriptRegistry::FindCourseResults(const std::string& courseName) const {
    std::list<std::pair<std::string, size_t>> results;
    for_each(transcripts.begin(), transcripts.end(),
        [&](Transcript trans) {
            for_each(trans.grades.begin(), trans.grades.end(),
                [&](std::pair<std::string, size_t> grade) {
                    if (grade.first == courseName){
                        std::pair<std::string, size_t> p(trans.student_id, grade.second);
                        results.push_back(p);
                    }
            });
        });
    return results;
}

// GetTranscripts: takes no parameters and returns a container that supports begin and end
// functions containing all the transcripts in the registry, in the order they were added.
const std::list<Transcript>& TranscriptRegistry::GetTranscripts() const {
   return transcripts;
}