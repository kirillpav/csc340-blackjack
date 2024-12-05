class Member {
    private: 
    std::string userName;
    int memberId;
    std::vector<Media> borrowedMedia; // push_back to add, remove or pop to return an item. 
    
    public: 
    Member();
    
    Member(std::string userName, int memberId);
    
    std::string getUserName() const;
    void setUserName(std::string newName);
    
    int getMemberId(int newMemberId) const;
    void setMemberId();
    
    void addMedia(const Media& mediaItem);
    void returnMedia(const std::string& mediaItemName);
}