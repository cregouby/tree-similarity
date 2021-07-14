// The MIT License (MIT)
// Copyright (c) 2021 Thomas Huetter
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

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "node.h"
#include "tree_indexer.h"
#include "label_set_element.h"
#include "lookup_result_element.h"
#include "two_stage_inverted_list.h"

namespace lookup {

/**
 * Implements a index lookup algorithm for a given verification and upper bound 
 * algorithm.
 */
template <typename Label, typename VerificationAlgorithm, typename UpperBound>
class VerificationUBkIndex {

public:
  VerificationUBkIndex();
  
  /// Executes the lookup algorithm.
  /**
   * \param trees_collection A vector holding an input collection of trees.
   * \param distance_threshold The maximum number of edit operations that
   *                           differs two trees in the lookup's result set.
   * \return A vector with the lookup result.
   */
  std::vector<lookup::LookupResultElement> execute_lookup(
      std::vector<node::Node<Label>>& trees_collection,
      std::vector<std::pair<int, std::vector<label_set_converter_index::LabelSetElement>>>& sets_collection,
      std::vector<std::pair<int, int>>& size_setid_map, lookup::TwoStageInvertedList& index,
      unsigned int query_tree_id, const double distance_threshold);
  
  double node_lower_bound(std::vector<label_set_converter_index::LabelSetElement>& r, 
      std::vector<label_set_converter_index::LabelSetElement>& s, 
      double olap, int pr, int ps);

  /// Returns the summed subproblem count of JEDI algorithm executions.
  /**
   * \return sum_subproblem_counter_
   */
  long long int get_subproblem_count() const;
  
  /// Returns the number of verifications.
  /**
   * \return verfications_
   */
  long long int get_verification_count() const;
  
  /// Returns the number of candidates.
  /**
   * \return candidates_
   */
  long long int get_candidates_count() const;
  
  /// Returns the number of pre_candidates.
  /**
   * \return pre_candidates_
   */
  long long int get_pre_candidates_count() const;

private:
  /// Number of subproblrems encoutered in the verification step.
  long long int sum_subproblem_counter_;
  /// Number of verification computations.
  long long int verfications_;
  /// Number of pre_candidates.
  long long int pre_candidates_;
  /// Number of candidates.
  long long int candidates_;
};

/**
 * Implements a index lookup algorithm for a given verification.
 */
template <typename Label, typename VerificationAlgorithm>
class VerificationIndex {

public:
  VerificationIndex();
  
  /// Executes the lookup algorithm.
  /**
   * \param trees_collection A vector holding an input collection of trees.
   * \param distance_threshold The maximum number of edit operations that
   *                           differs two trees in the lookup's result set.
   * \return A vector with the lookup result.
   */
  std::vector<lookup::LookupResultElement> execute_lookup(
      std::vector<node::Node<Label>>& trees_collection,
      std::vector<std::pair<int, std::vector<label_set_converter_index::LabelSetElement>>>& sets_collection,
      std::vector<std::pair<int, int>>& size_setid_map, lookup::TwoStageInvertedList& index,
      unsigned int query_tree_id, const double distance_threshold);
  
  double node_lower_bound(std::vector<label_set_converter_index::LabelSetElement>& r, 
      std::vector<label_set_converter_index::LabelSetElement>& s, 
      double olap, int pr, int ps);

  /// Returns the summed subproblem count of JEDI algorithm executions.
  /**
   * \return sum_subproblem_counter_
   */
  long long int get_subproblem_count() const;
  
  /// Returns the number of verifications.
  /**
   * \return verfications_
   */
  long long int get_verification_count() const;
  
  /// Returns the number of candidates.
  /**
   * \return candidates_
   */
  long long int get_candidates_count() const;
  
  /// Returns the number of pre_candidates.
  /**
   * \return pre_candidates_
   */
  long long int get_pre_candidates_count() const;

private:
  /// Number of subproblrems encoutered in the verification step.
  long long int sum_subproblem_counter_;
  /// Number of verification computations.
  long long int verfications_;
  /// Number of pre_candidates.
  long long int pre_candidates_;
  /// Number of candidates.
  long long int candidates_;
};

// Implementation details.
#include "index_impl.h"

}
