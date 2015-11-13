#ifndef THESEUS_MODEL_NODE
#define THESEUS_MODEL_NODE
#include <vector>
namespace theseus {
namespace model {
	class Node {
		private:
			int name;
			std::vector<Node *> edges;

		public:
			Node(int name);
			int getName();
			std::vector<Node>* getEdges();
			void setEdges(std::vector<Node *> edges);
	};
}
}
#endif
