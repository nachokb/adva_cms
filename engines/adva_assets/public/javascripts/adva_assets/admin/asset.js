(function($){
  $.fn.identify = function(count) {
    return this.each(function() {
      $(this).find(":input").each(function() {
        $(this).attr("id", $(this).attr("id").replace("0", count))
               .attr("name", $(this).attr("name").replace("0", count));
      });
    });
 };
})(jQuery);

var Assets = {
  observe: function() {
    // $(".assets_row div").bind("mouseover mouseout", function(){ $(this).find("ul:first").toggle(); });
    $(".assets_row div").bind("mouseover", function(){ $(this).find("ul:first").show(); });
    $(".assets_row div").bind("mouseout", function(){ $(this).find("ul:first").hide(); });
  }
};

var AssetForm = $.klass({
  initialize: function() {
    $("#asset_add_file").bind("click", this.addInput);
    $("#tagall_files").bind("click", this.applyTagsToAll);
  },
  addInput: function() {
    var list = $("#files div"), copyFrom = list.find("p:first"), tagall = $("#tagall_files");
    var newNode = copyFrom.clone(true), files = list.children("p");
    newNode.find("input").each(function(){ $(this).val("") });
    var close = newNode.find(".remove_file:first").show();
    newNode.find(".tagall_files:first").remove();
    newNode.identify(files.length);
    close.click(function(){
      $(this).parent("p").remove();
      if(tagall.is(":visible") && files.length == 1) tagall.hide();
    });
    if(!tagall.is(":visible") && files.length > 0) tagall.show();
    newNode.appendTo(list);
  },
  applyTagsToAll: function() {
    // TODO DRY/clean-up map and trim tags stuff
    var tags = $(this).siblings(".taglist_field").val().split(" ");
    tags = jQuery.map(tags, function(tag, i){ return jQuery.trim(tag.toString()); });
    $("#files div p input.taglist_field").each(function(){
      var localTags = $(this).val().split(" ");
      localTags = jQuery.map(localTags, function(tag, i){ return jQuery.trim(tag.toString()); });
      jQuery.each(tags, function(){
        if(jQuery.inArray(this.toString(), localTags) < 0)
          localTags.push(this.toString());
      });
      $(this).val(jQuery.trim(localTags.join(" ")));
    });
  }
});

$().ready(function(){ new AssetForm(); Assets.observe(); });
