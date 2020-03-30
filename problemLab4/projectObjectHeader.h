#pragma once

class Project {
private:
	char* path;
	int branches;
	int commits;
public:
	Project();
	Project(const char*, int, int);
	Project(const Project&);
	char* getPath();
	int getBranches();
	int getCommits();
	void setPath(char*);
	void setBranches(int);
	void setCommits(int);
	~Project();
	Project& operator=(const Project&);
	bool operator==(const Project&);
};