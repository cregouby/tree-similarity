// The MIT License (MIT)
// Copyright (c) 2017 Mateusz Pawlik, Nikolaus Augsten, and Daniel Kocher.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

/// \file tree_similarity.cc
///
/// \details
/// Entry point of the tree similarity command-line interface.

#include "tree_similarity.h"
#include <iostream>

template<class _Label> using CostModel = cost_model::UnitCostModel<_Label>;

int main(int argc, char** argv) {
    // TODO: using Parser = ;
    using Label = label::StringLabel;


    node::Node<Label> root(Label("abc"));
    node::Node<Label> root2(Label("abcd"));
    node::Node<Label> root3(Label("abc"));

    CostModel<Label> cost_model;

    std::cout << cost_model.ren(root, root2) << std::endl;
    std::cout << cost_model.ren(root, root3) << std::endl;
    std::cout << cost_model.ren(root2, root) << std::endl;
    std::cout << cost_model.ren(root2, root3) << std::endl;
    std::cout << cost_model.ren(root3, root) << std::endl;
    std::cout << cost_model.ren(root3, root2) << std::endl;

    std::cout << "root: " << root.children_count() << std::endl;

    node::Node<Label> child1(Label("def"));

    child1.add_child(node::Node<Label>(Label("d")));
    child1.add_child(node::Node<Label>(Label("e")));
    child1.add_child(node::Node<Label>(Label("f")));

    std::cout << "child1: " << child1.children_count() << std::endl;

    node::Node<Label> child2(Label("gh"));

    child2.add_child(node::Node<Label>(Label("g")));
    child2.add_child(node::Node<Label>(Label("h")));

    std::cout << "child2: " << child2.children_count() << std::endl;

    node::Node<Label> child3(Label("ijkl"));

    child3.add_child(node::Node<Label>(Label("i")));
    child3.add_child(node::Node<Label>(Label("j")));
    child3.add_child(node::Node<Label>(Label("k")));
    child3.add_child(node::Node<Label>(Label("l")));

    std::cout << "child3: " << child3.children_count() << std::endl;

    root.add_child(std::move(child1));
    root.add_child(std::move(child2));
    root.add_child(std::move(child3));

    std::cout << "root: " << root.children_count() << std::endl;
    std::cout << "child1: " << child1.children_count() << std::endl;
    std::cout << "child2: " << child2.children_count() << std::endl;
    std::cout << "child3: " << child3.children_count() << std::endl;

    node::Node<Label> r1_1(Label("a"));
    node::Node<Label> n1_2(Label("a"));
    node::Node<Label> n1_3(Label("a"));
    node::Node<Label> n1_4(Label("a"));
    node::Node<Label> n1_5(Label("a"));
    node::Node<Label> n1_6(Label("a"));
    node::Node<Label> n1_7(Label("a"));
    n1_5.add_child(std::move(n1_7));
    n1_3.add_child(std::move(n1_4));
    n1_3.add_child(std::move(n1_5));
    n1_3.add_child(std::move(n1_6));
    r1_1.add_child(std::move(n1_2));
    r1_1.add_child(std::move(n1_3));

    node::Node<Label> r2_1(Label("b"));
    node::Node<Label> n2_2(Label("a"));
    node::Node<Label> n2_3(Label("a"));
    node::Node<Label> n2_4(Label("b"));
    node::Node<Label> n2_5(Label("a"));
    node::Node<Label> n2_6(Label("b"));
    node::Node<Label> n2_7(Label("a"));
    n2_5.add_child(std::move(n2_7));
    n2_3.add_child(std::move(n2_4));
    n2_3.add_child(std::move(n2_5));
    n2_3.add_child(std::move(n2_6));
    r2_1.add_child(std::move(n2_2));
    r2_1.add_child(std::move(n2_3));

    zhang_shasha::Algorithm<Label, CostModel<Label>> zs_ted(r1_1, r2_1, cost_model);
    std::cout << zs_ted.zhang_shasha_ted() << std::endl;

    return 0;
}
